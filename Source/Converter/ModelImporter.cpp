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
			aiProcess_ImproveCacheLocality | aiProcess_FindInstances |
			aiProcess_Debone | aiProcess_FixInfacingNormals | aiProcess_FindInvalidData : 0) |
			(leftHanded ? aiProcess_ConvertToLeftHanded : 0));
	if (pScene) {
		m_pScene = pScene;
		m_filename = std::string(filename.c_str());
		return true;
	}

	std::cout << m_pImporter->GetErrorString() << "\n";
	return false;
}

void ModelImporter::importModel(ModelVec& aModels, MeshVec& aMeshes, SkelMeshVec& aSkelMeshes,
	MatVec& aMaterials, TexVec& aTextures, definition::ResourceName& aNames,
	bool extractMaterialsAndTexture) {

	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return;
	}

	extractMeshes(aModels, aMeshes, aNames);
	extractSkeletalMeshes(aModels, aSkelMeshes, aNames);
	if (extractMaterialsAndTexture) {
		extractMaterials(aMaterials, aNames);
		extractTextures(aTextures, aNames);
	}
}

void ModelImporter::extractMeshes(ModelVec& aOutModelVec, MeshVec& aOutMeshVec,
	definition::ResourceName& aNames) {
	aOutModelVec.resize(m_pScene->mNumMeshes);
	aOutMeshVec.resize(m_pScene->mNumMeshes);
	aiString str;
	for (U32 i = 0u, size = m_pScene->mNumMeshes; i < size; ++i) {
		aiMesh* inMesh = m_pScene->mMeshes[i];
		if (!inMesh->HasBones()) {
			aOutMeshVec[i].name = inMesh->mName.C_Str();
			aNames.names[aOutMeshVec[i].name] = definition::EFileType::MESH;
			extractVertex(inMesh, aOutMeshVec[i]);
			AddIndices(inMesh, aOutMeshVec[i]);
			m_pScene->mMaterials[inMesh->mMaterialIndex]->Get(AI_MATKEY_NAME, str);
			if (str != aiString("")) {
				aNames.names[aOutModelVec[i].mesh] =
					definition::EFileType(definition::EFileType::MESH | definition::EFileType::MODEL);
				aOutModelVec[i].mesh = inMesh->mName.C_Str();
				aOutModelVec[i].material = str.C_Str();
				str.Clear();
			}
		}
	}
}

void ModelImporter::extractSkeletalMeshes(ModelVec& aOutModelVec, SkelMeshVec& aOutMeshVec,
	definition::ResourceName& aNames) {
	aOutModelVec.resize(m_pScene->mNumMeshes);
	aOutMeshVec.resize(m_pScene->mNumMeshes);
	aiString str;
	for (U32 i = 0u, size = m_pScene->mNumMeshes; i < size; ++i) {
		aiMesh* inMesh = m_pScene->mMeshes[i];
		if (inMesh->HasBones()) {
			aOutMeshVec[i].name = inMesh->mName.C_Str();
			aNames.names[aOutMeshVec[i].name] = definition::EFileType::MESH;
			extractSkeleton(inMesh, aOutMeshVec[i].skeleton);
			extractSkeletalVertex(inMesh, aOutMeshVec[i]);
			AddIndices(inMesh, aOutMeshVec[i]);
			m_pScene->mMaterials[inMesh->mMaterialIndex]->Get(AI_MATKEY_NAME, str);
			if (str != aiString("")) {
				aNames.names[aOutModelVec[i].mesh] =
					definition::EFileType(definition::EFileType::MESH | definition::EFileType::MODEL);
				aOutModelVec[i].mesh = inMesh->mName.C_Str();
				aOutModelVec[i].material = str.C_Str();
				str.Clear();
			}
		}
	}
}

void ModelImporter::extractMaterials(MatVec& aOutMatVec, definition::ResourceName& aNames) {
	aOutMatVec.resize(m_pScene->mNumMaterials);
	for (U32 i = 0u, size = m_pScene->mNumMaterials; i < size; ++i) {
		aiString str;
		aiVector3D temp;
		m_pScene->mMaterials[i]->Get(AI_MATKEY_NAME, str);
		aOutMatVec[i].name = str.C_Str();
		str.Clear();
		aNames.names[aOutMatVec[i].name] = definition::EFileType::MATERIAL;
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
		m_pScene->mMaterials[i]->Get(AI_MATKEY_COLOR_TRANSPARENT, temp);
		aOutMatVec[i].transparentColor = *reinterpret_cast<math::Vec3f*>(&temp);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_OPACITY, aOutMatVec[i].opacity);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS, aOutMatVec[i].shininess);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_SHININESS_STRENGTH, aOutMatVec[i].shininessStrength);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_TWOSIDED, aOutMatVec[i].twoSided);
		m_pScene->mMaterials[i]->Get(AI_MATKEY_ENABLE_WIREFRAME, aOutMatVec[i].wireframe);
	}
}

void ModelImporter::extractTextures(TexVec& aOutTexVec, definition::ResourceName& aNames) {
	aOutTexVec.resize(m_textureToLoadLater.size());
	int i = 0;
	for (auto& texture : m_textureToLoadLater) {
		definition::Texture& temp = aOutTexVec[i];
		const aiTexture* tex;
		if (tex = m_pScene->GetEmbeddedTexture(std::get<0>(texture).c_str())) {
			if (tex->mHeight) {
				temp.width = tex->mWidth;
				temp.height = tex->mHeight;
				temp.pixels.resize(temp.height * temp.width * 4);
				memcpy(temp.pixels.data(), (U8*)tex->pcData,
					temp.width * temp.height * 4);
				temp.channels = 4;
				temp.format = GL_RGBA8;
			}
			else {
				I32 height, width, channels;
				U8* pixels = stbi_load_from_memory((U8*)tex->pcData,
					tex->mWidth, &width, &height, &channels, 0);
				temp.pixels.resize(height * width * channels);
				memcpy(temp.pixels.data(), pixels, width * height * channels);
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
		aNames.names[temp.name] = definition::EFileType::TEXTURE;
		++i;
	}
}

void ModelImporter::extractVertex(aiMesh* inMesh, definition::Mesh& outMesh) {
	outMesh.vertices.resize(inMesh->mNumVertices);
	for (U32 i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.vertices[i] =
		(definition::Vertex{ *reinterpret_cast<math::Vec3f*>(inMesh->mVertices + i),
			*reinterpret_cast<math::Vec3f*>(inMesh->mNormals + i),
			*reinterpret_cast<math::Vec2f*>(inMesh->mTextureCoords[0] + i) });
	}
}

void ModelImporter::extractSkeletalVertex(aiMesh* inMesh, definition::SkeletalMesh& outMesh) {
	definition::SkeletalVertex skelVert;
	outMesh.vertices.resize(inMesh->mNumVertices);
	for (U32 i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		skelVert.pos = *reinterpret_cast<math::Vec3f*>(inMesh->mVertices + i);
		skelVert.normal = *reinterpret_cast<math::Vec3f*>(inMesh->mNormals + i);
		skelVert.uv = *reinterpret_cast<math::Vec2f*>(inMesh->mTextureCoords[0] + i);
		outMesh.vertices[i] = skelVert;
	}
	std::map<U32, std::pair<std::vector<U32>, std::vector<F32>>> weightMap;
	for (U32 size = inMesh->mNumBones, i = 0; i < size; ++i) {
		aiBone* bone = inMesh->mBones[i];
		for (U32 i2 = 0, size2 = bone->mNumWeights; i2 < size2; ++i2) {
			std::pair<std::vector<U32>, std::vector<F32>>& weightPair =
				weightMap[bone->mWeights[i2].mVertexId];
			weightPair.first.emplace_back(i);
			weightPair.second.emplace_back(bone->mWeights[i2].mWeight);
		}
	}
	for (auto& weightNode : weightMap) {
		outMesh.vertices[weightNode.first].boneId = math::Vec4u(weightNode.second.first.data());
		outMesh.vertices[weightNode.first].weight = math::Vec4f(weightNode.second.second.data());
	}
}

void ModelImporter::extractSkeleton(aiMesh* inMesh, definition::Skeleton& outSkeleton) {
	if (inMesh->HasBones()) {
		new (&outSkeleton.invGlobalPos) math::Mat4f(m_pScene->mRootNode->mTransformation[0]);
		outSkeleton.invGlobalPos.inverse();
		aiVector3D pos, scale;
		aiQuaternion quat;
		for (unsigned int size = inMesh->mNumBones, i = 0; i < size; ++i) {
			if (inMesh->mBones[i]->mName.length) {
				definition::Bone& b = outSkeleton.bones[inMesh->mBones[i]->mName.C_Str()];
				b.name = inMesh->mBones[i]->mName.C_Str();
				definition::Joint& j = b.joint;
				inMesh->mBones[i]->mOffsetMatrix.Decompose(scale, quat, pos);
				new (&j.pos) math::Vec3f((F32*)&pos);
				new (&j.rot) math::Quat(math::Vec4f((F32*)&quat));
				new (&j.scale) math::Vec3f((F32*)&scale);
			}
		}
		buildBoneHierarchy(m_pScene->mRootNode->FindNode(inMesh->mBones[0]->mName.C_Str()),
			outSkeleton.bones[std::string(inMesh->mBones[0]->mName.C_Str())], outSkeleton);
	}
	if (m_pScene->HasAnimations()) {
		extractAnimation(outSkeleton.animations);
		outSkeleton.optimizeBoneList();
		outSkeleton.interpolateKeyframe();
	}
}

void ModelImporter::buildBoneHierarchy(aiNode* inNode, definition::Bone& b,
	definition::Skeleton& skeleton) {
	b.children.reserve(inNode->mNumChildren);
	for (unsigned int i = 0, size = inNode->mNumChildren; i < size; ++i) {
		if (inNode->mChildren[i]->mName.length) {
			b.children.emplace_back(std::string(inNode->mChildren[i]->mName.C_Str()));
			skeleton.bones[b.children[b.children.size() - 1]].parent = b.name;

			buildBoneHierarchy(inNode->mChildren[i],
				skeleton.bones[std::string(inNode->mChildren[i]->mName.C_Str())], skeleton);
		}
		else {
			buildBoneHierarchy(inNode->mChildren[i], b, skeleton);
		}
	}
}

void ModelImporter::extractAnimation(std::vector<definition::Animation>& outAnimations) {
	outAnimations.resize(m_pScene->mNumAnimations);
	for (U32 i = 0, size = m_pScene->mNumAnimations; i < size; ++i) {
		aiAnimation* aiAnim = m_pScene->mAnimations[i];
		definition::Animation& anim = outAnimations[i];
		anim.animationDuration = (F32)aiAnim->mDuration;
		anim.tickPerSecond = (F32)aiAnim->mTicksPerSecond;
		anim.name = std::string(aiAnim->mName.C_Str());
		for (U32 i2 = 0, size2 = aiAnim->mNumChannels; i2 < size2; ++i2) {
			extractKeyframe(aiAnim->mChannels[i2], anim.frames);
		}
		if (!anim.tickPerSecond) {
			anim.tickPerSecond = (F32)anim.frames.size() /
				(F32)(aiAnim->mDuration ? aiAnim->mDuration : 1.f);
		}
	}
}

void ModelImporter::extractKeyframe(aiNodeAnim* inKeyframe, std::vector<definition::Keyframe>& outKeyframe) {
	U32 outKeyframeSize = (U32)outKeyframe.size();
	U32 max = std::max(inKeyframe->mNumPositionKeys,
		std::max(inKeyframe->mNumRotationKeys, inKeyframe->mNumScalingKeys));
	if(outKeyframeSize < max)
		outKeyframe.resize(max);
	for (U32 i = 0, size = inKeyframe->mNumPositionKeys; i < size; ++i) {
		definition::Joint& j = outKeyframe[i].joints[std::string(inKeyframe->mNodeName.C_Str())];
		j.pos = *reinterpret_cast<math::Vec3f*>(&inKeyframe->mPositionKeys[i].mValue);
	}
	for (U32 i = 0, size = inKeyframe->mNumRotationKeys; i < size; ++i) {
		definition::Joint& j = outKeyframe[i].joints[std::string(inKeyframe->mNodeName.C_Str())];
		j.rot = *reinterpret_cast<math::Quat*>(&inKeyframe->mRotationKeys[i].mValue);
	}
	for (U32 i = 0, size = inKeyframe->mNumScalingKeys; i < size; ++i) {
		definition::Joint& j = outKeyframe[i].joints[std::string(inKeyframe->mNodeName.C_Str())];
		j.scale = *reinterpret_cast<math::Vec3f*>(&inKeyframe->mScalingKeys[i].mValue);
	}
}

template<typename MeshType>
void ModelImporter::AddIndices(aiMesh* inMesh, MeshType& outMesh) {
	outMesh.indices.resize(inMesh->mNumFaces * 3);
	for (U32 f = 0u; f < inMesh->mNumFaces; ++f) {
		const aiFace& inFace = inMesh->mFaces[f];
		if (inFace.mNumIndices == 3u) {
			outMesh.indices[f] = inFace.mIndices[0];
			outMesh.indices[f + 1] = inFace.mIndices[1];
			outMesh.indices[f + 2] = inFace.mIndices[2];
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
	aOutTexture.pixels.resize(height * width * channels);
	memcpy(aOutTexture.pixels.data(), pixels, width * height * channels);
}

} // namespace importer
} // namespace tools
} // namespace drak