#include <PrecompiledHeader/pch.hpp>

#include <iostream>
#include <Converter/ModelImporter.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace drak {
namespace tools {

ModelImporter::ModelImporter()
:	m_pScene(nullptr), m_pImporter(new Assimp::Importer) {
}

ModelImporter::~ModelImporter() {
}

bool ModelImporter::startImport(const std::string& filename, bool optimizeMesh, bool leftHanded) {
	const aiScene* pScene = m_pImporter->ReadFile(
		filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate	|
		aiProcess_SortByPType	|
		aiProcess_RemoveRedundantMaterials |
		aiProcess_GenNormals	|
		aiProcess_GenUVCoords   |
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

void ModelImporter::importModel(ModelVec& aModels,
	MatVec& aMaterials, TexVec& aTextures, bool extractMaterialsAndTexture) {

	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return;
	}

	extractModels(aModels);

	if (extractMaterialsAndTexture) {
		extractMaterials(aMaterials);
		extractTextures(aTextures);
	}
}

void ModelImporter::importSkeletalModel(SkelMeshVec& aMeshes,
	MatVec& aMaterials, TexVec& aTextures, bool extractMaterialsAndTexture) {
}

void ModelImporter::extractModels(ModelVec& aOutModelVec) {
	aOutModelVec.insert(aOutModelVec.begin(), m_pScene->mNumMeshes, Model<Mesh>());
	for (U32 i = 0u, size = m_pScene->mNumMeshes; i < size; ++i) {
		aiMesh* inMesh = m_pScene->mMeshes[i];
		extractVertex(inMesh, aOutModelVec[i].mesh);
		m_pScene->mMaterials[inMesh->mMaterialIndex]->Get(AI_MATKEY_NAME, aOutModelVec[i].material);
	}
}

void ModelImporter::extractSkeletalModels(SkelMeshVec& aOutMeshVec) {

}

void ModelImporter::extractMaterials(MatVec& aOutMatVec) {
	aOutMatVec.insert(aOutMatVec.begin(), m_pScene->mNumMaterials, Material());
	for (U32 i = 0u, size = m_pScene->mNumMaterials; i < size; ++i) {
		m_pScene->mMaterials[i]->Get(AI_MATKEY_NAME, aOutMatVec[i].name);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_TEXTURE_DIFFUSE(0), aOutMatVec[i].albedo);
		if (aOutMatVec[i].albedo[0] != '*' &&
			drak::io::FileExists(aOutMatVec[i].albedo.c_str()) == core::EError::NO_ERROR) {
			m_textureToLoadLater.emplace_back(std::tuple<std::string&>(aOutMatVec[i].albedo));
		}
		else if(aOutMatVec[i].normal[0] != '*') {
			std::cout << "Texture at Path" << aOutMatVec[i].albedo << " not found \n";
			aOutMatVec[i].albedo = "";
		}
		else {
			aOutMatVec[i].albedo.erase(std::remove(aOutMatVec[i].albedo.begin(),
				aOutMatVec[i].albedo.end(), '*'), aOutMatVec[i].albedo.end());
			aOutMatVec[i].albedo = m_filename + std::string("Texture") + aOutMatVec[i].albedo;
		}
		m_pScene->mMaterials[i]->Get(AI_MATKEY_TEXTURE_NORMALS(0), aOutMatVec[i].normal);
		if (aOutMatVec[i].normal[0] != '*' &&
			drak::io::FileExists(aOutMatVec[i].normal.c_str()) == core::EError::NO_ERROR) {
			m_textureToLoadLater.emplace_back(std::tuple<std::string&>(aOutMatVec[i].normal));
		}
		else if(aOutMatVec[i].normal[0] != '*'){
			std::cout << "Texture at Path" << aOutMatVec[i].normal << " not found\n";
			aOutMatVec[i].normal = "";
		}
		else {
			aOutMatVec[i].normal.erase(std::remove(aOutMatVec[i].normal.begin(),
				aOutMatVec[i].normal.end(), '*'), aOutMatVec[i].normal.end());
			aOutMatVec[i].normal = m_filename + std::string("Texture") + aOutMatVec[i].normal;
		}
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_DIFFUSE, aOutMatVec[i].diffuseColor);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_SPECULAR, aOutMatVec[i].specularColor);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_AMBIENT, aOutMatVec[i].ambientColor);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_OPACITY, aOutMatVec[i].opacity);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS, aOutMatVec[i].shininess);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS_STRENGTH, aOutMatVec[i].shininessStrength);
	}
}

void ModelImporter::extractTextures(TexVec& aOutTexVec) {
	aOutTexVec.insert(aOutTexVec.begin(),
		m_pScene->mNumTextures + m_textureToLoadLater.size(), Texture());
	for (U32 i = 0u, size = m_pScene->mNumTextures; i < size; ++i) {
		Texture& temp = aOutTexVec[i];
		temp.name = m_filename + std::string("Texture") + std::to_string(i);
		if (m_pScene->mTextures[i]->mHeight) {
			temp.width = m_pScene->mTextures[i]->mWidth;
			temp.height = m_pScene->mTextures[i]->mHeight;
			temp.pixels.resize(aOutTexVec[i].height * aOutTexVec[i].width);
			memcpy(temp.pixels.data(), (U8*)m_pScene->mTextures[i]->pcData,
				temp.width * temp.height);
			temp.channels = 4;
			temp.format = GL_RGBA8;
		}
		else {
			I32 height, width, channels;
			U8* pixels = stbi_load_from_memory((U8*)m_pScene->mTextures[i]->pcData,
				(U32)strlen((const char*)m_pScene->mTextures[i]->pcData), &width, &height, &channels, 0);
			temp.pixels.resize(height * width);
			memcpy(temp.pixels.data(), pixels, width * height);
			temp.format = channels == 3 ? GL_RGB8 : GL_RGBA8;
			temp.channels = channels;
			temp.height = height;
			temp.width = width;
		}
	}
	int i = 0;
	for (auto& texture : m_textureToLoadLater) {
		Texture& temp = aOutTexVec[m_pScene->mNumTextures + i];
		loadTextureFromFile(std::get<0>(texture), temp);
		std::get<0>(texture) = m_filename + std::string("Texture") + std::to_string(m_pScene->mNumTextures + i);
		temp.name = std::get<0>(texture);
	}
}

void ModelImporter::extractVertex(aiMesh* inMesh, Mesh& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.vertices.emplace_back(Vertex{ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])),
			*reinterpret_cast<math::Vec3f*>(&(inMesh->mNormals[i])),
			*reinterpret_cast<math::Vec2f*>(&(inMesh->mTextureCoords[i])) });
	}
}

void ModelImporter::extractSkeletalVertex(aiMesh* inMesh, SkeletalMesh& outMesh) {
}

template<typename MeshType>
void ModelImporter::AddIndices(aiMesh* inMesh, MeshType& outMesh) {
	for (U32 f = 0u; f < inMesh->mNumFaces; ++f) {
		const aiFace& inFace = inMesh->mFaces[f];
		if (inFace.mNumIndices == 3u) {
			outMesh.indices(
				inFace.mIndices[0],
				inFace.mIndices[1],
				inFace.mIndices[2]);
		}
	}
}

void loadTextureFromFile(const std::string& filename, Texture& aOutTexture) {
	I32 height, width, channels;
	U8* pixels = stbi_load(filename.c_str(), &width, &height, &channels, 0);
	aOutTexture.name = filename;
	aOutTexture.width = width;
	aOutTexture.height = height;
	aOutTexture.channels = channels;
	aOutTexture.format = channels == 3 ? GL_RGB8 : GL_RGBA8;
	aOutTexture.pixels.resize(height * width);
	memcpy(aOutTexture.pixels.data(), pixels, width * height);
}

} // namespace tools
} // namespace drak