#include <PrecompiledHeader/pch.hpp>

#include <Converter/ModelImporter.hpp>
#include <Core/Utils/FileUtils.hpp>

#include <assimp/config.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace drak {
namespace tools {
namespace importer {

ModelImporter::ModelImporter()
:	m_pScene(nullptr), m_pImporter(new Assimp::Importer) {
}

ModelImporter::ModelImporter(const ModelImporter& m) : m_pScene(nullptr),
	m_pImporter(m.m_pImporter) {
}

ModelImporter::ModelImporter(ModelImporter&& m) : m_pScene(std::move(m.m_pScene)),
	m_pImporter(std::move(m.m_pImporter)) {
	m.m_pScene = nullptr;
	m.m_pImporter = nullptr;
}

ModelImporter::~ModelImporter() {
}

ModelImporter& ModelImporter::operator=(const ModelImporter& m) {
	m_pScene = nullptr;
	m_pImporter = new Assimp::Importer;
	return *this;
}

ModelImporter& ModelImporter::operator=(ModelImporter&& m) {
	m_pScene = std::move(m.m_pScene);
	m_pImporter = std::move(m.m_pImporter);
	m.m_pScene = nullptr;
	m.m_pImporter = nullptr;
	return *this;
}

bool ModelImporter::operator==(const ModelImporter& m) {
	return m_pImporter == m.m_pImporter;
}

bool ModelImporter::startImport(const std::string& filename, bool optimizeMesh, bool leftHanded) {
	m_textureToLoadLater.clear();
	const aiScene* pScene = m_pImporter->ReadFile(
		filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate |
		aiProcess_SortByPType |
		aiProcess_RemoveRedundantMaterials |
		aiProcess_GenNormals |
		aiProcess_GenUVCoords |
		(optimizeMesh ? aiProcess_OptimizeMeshes |
			aiProcess_OptimizeGraph |
			aiProcess_ImproveCacheLocality : 0) |
			(leftHanded ? aiProcess_ConvertToLeftHanded : 0));
	if (pScene) {
		m_pScene = pScene;
		m_filename = std::string(filename.c_str());
		return true;
	}

	std::cout << m_pImporter->GetErrorString() << "\n";
	return false;
}

void ModelImporter::importModel(ModelVec& aModels, MeshVec& aMeshes,
	MatVec& aMaterials, TexVec& aTextures, bool extractMaterialsAndTexture) {

	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return;
	}

	extractMeshes(aModels, aMeshes);
	if (extractMaterialsAndTexture) {
		extractMaterials(aMaterials);
		extractTextures(aTextures);
	}
}

void ModelImporter::importSkeletalModel(ModelVec& aModels, SkelMeshVec& aSkelMeshes,
	MatVec& aMaterials, TexVec& aTextures, bool extractMaterialsAndTexture) {
}

void ModelImporter::extractMeshes(ModelVec& aOutModelVec, MeshVec& aOutMeshVec) {
	aOutModelVec.insert(aOutModelVec.begin(), m_pScene->mNumMeshes, definition::Model());
	aOutMeshVec.insert(aOutMeshVec.begin(), m_pScene->mNumMeshes, definition::Mesh());
	aiString str;
	for (U32 i = 0u, size = m_pScene->mNumMeshes; i < size; ++i) {
		aiMesh* inMesh = m_pScene->mMeshes[i];
		aOutModelVec[i].mesh = aOutMeshVec[i].name = inMesh->mName.C_Str();
		extractVertex(inMesh, aOutMeshVec[i]);
		AddIndices(inMesh, aOutMeshVec[i]);
		m_pScene->mMaterials[inMesh->mMaterialIndex]->Get(AI_MATKEY_NAME, str);
		aOutModelVec[i].material = str.C_Str();
		str.Clear();
	}
}

void ModelImporter::extractSkeletalMeshes(ModelVec& aOutModelVec, SkelMeshVec& aOutMeshVec) {

}

void ModelImporter::extractMaterials(MatVec& aOutMatVec) {
	aOutMatVec.insert(aOutMatVec.begin(), m_pScene->mNumMaterials, definition::Material());
	for (U32 i = 0u, size = m_pScene->mNumMaterials; i < size; ++i) {
		aiString str;
		aiVector3D temp;
		m_pScene->mMaterials[i]->Get(AI_MATKEY_NAME, str);
		aOutMatVec[i].name = str.C_Str();
		str.Clear();
		m_pScene->mMaterials[i]->Get(AI_MATKEY_TEXTURE_DIFFUSE(0), str);
		aOutMatVec[i].albedo = str.C_Str();
		str.Clear();
		if(aOutMatVec[i].albedo != "")
			m_textureToLoadLater.emplace_back(std::tuple<std::string&>(aOutMatVec[i].albedo));
		m_pScene->mMaterials[i]->Get(AI_MATKEY_TEXTURE_NORMALS(0), str);
		aOutMatVec[i].normal = str.C_Str();
		str.Clear();
		if (aOutMatVec[i].normal != "")
			m_textureToLoadLater.emplace_back(std::tuple<std::string&>(aOutMatVec[i].normal));
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_DIFFUSE, temp);
		aOutMatVec[i].diffuseColor = *reinterpret_cast<math::Vec3f*>(&temp);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_SPECULAR, temp);
		aOutMatVec[i].specularColor = *reinterpret_cast<math::Vec3f*>(&temp);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_AMBIENT, temp);
		aOutMatVec[i].ambientColor = *reinterpret_cast<math::Vec3f*>(&temp);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_OPACITY, aOutMatVec[i].opacity);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS, aOutMatVec[i].shininess);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS_STRENGTH, aOutMatVec[i].shininessStrength);
	}
}

void ModelImporter::extractTextures(TexVec& aOutTexVec) {
	aOutTexVec.insert(aOutTexVec.begin(), m_textureToLoadLater.size(), definition::Texture());
	int i = 0;
	for (auto& texture : m_textureToLoadLater) {
		definition::Texture& temp = aOutTexVec[i];
		const aiTexture* tex;
		if (tex = m_pScene->GetEmbeddedTexture(std::get<0>(texture).c_str())) {
			if (tex->mHeight) {
				temp.width = tex->mWidth;
				temp.height = tex->mHeight;
				temp.pixels.reserve(temp.height * temp.width);
				memcpy(temp.pixels.data(), (U8*)tex->pcData,
					temp.width * temp.height);
				temp.pixels.resize(temp.height * temp.width);
				temp.channels = 4;
				temp.format = GL_RGBA8;
			}
			else {
				I32 height, width, channels;
				U8* pixels = stbi_load_from_memory((U8*)tex->pcData,
					tex->mWidth, &width, &height, &channels, 0);
				temp.pixels.reserve(height * width);
				memcpy(temp.pixels.data(), pixels, width * height);
				temp.pixels.resize(height * width);
				temp.format = channels == 3 ? GL_RGB8 : GL_RGBA8;
				temp.channels = channels;
				temp.height = height;
				temp.width = width;
			}
		}
		else if (io::FileExists(std::get<0>(texture).c_str()) == DK_OK)
			loadTextureFromFile(std::get<0>(texture), temp);
		else {
			std::cout << "Failed to extract Texture : " <<
				std::get<0>(texture) << " in : " << m_filename << "\n";
			continue;
		}
		std::get<0>(texture) = m_pScene->GetShortFilename(m_filename.c_str()) +
			std::string("Texture") + std::to_string(i);
		temp.name = std::get<0>(texture);
		++i;
	}
}

void ModelImporter::extractVertex(aiMesh* inMesh, definition::Mesh& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.vertices.emplace_back
		(definition::Vertex{ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])),
			*reinterpret_cast<math::Vec3f*>(&(inMesh->mNormals[i])),
			(*reinterpret_cast<math::Vec3f*>(&(inMesh->mTextureCoords[0][i]))).xy });
	}
}

void ModelImporter::extractSkeletalVertex(aiMesh* inMesh, definition::SkeletalMesh& outMesh) {
}

template<typename MeshType>
void ModelImporter::AddIndices(aiMesh* inMesh, MeshType& outMesh) {
	for (U32 f = 0u; f < inMesh->mNumFaces; ++f) {
		const aiFace& inFace = inMesh->mFaces[f];
		if (inFace.mNumIndices == 3u) {
			outMesh.indices.emplace_back(inFace.mIndices[0]);
			outMesh.indices.emplace_back(inFace.mIndices[1]);
			outMesh.indices.emplace_back(inFace.mIndices[2]);
		}
	}
}

void loadTextureFromFile(const std::string& filename, definition::Texture& aOutTexture) {
	I32 height, width, channels;
	U8* pixels = stbi_load(filename.c_str(), &width, &height, &channels, 0);
	aOutTexture.name = filename;
	aOutTexture.width = width;
	aOutTexture.height = height;
	aOutTexture.channels = channels;
	aOutTexture.format = channels == 3 ? GL_RGB8 : GL_RGBA8;
	aOutTexture.pixels.reserve(height * width);
	memcpy(aOutTexture.pixels.data(), pixels, width * height);
	aOutTexture.pixels.resize(height * width);
}

} // namespace importer
} // namespace tools
} // namespace drak