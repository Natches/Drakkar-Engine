#include <iostream>
#include <Converter/ModelImporter.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace drak {
namespace tools {

ModelImporter::ModelImporter()
:	m_pScene(nullptr), m_pImporter(new Assimp::Importer) {
}

ModelImporter::~ModelImporter() {
	delete m_pImporter;
}

bool ModelImporter::startImport(const std::string& filename, bool leftHanded) {
	const aiScene* pScene = m_pImporter->ReadFile(
		filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate	|
		aiProcess_SortByPType	|
		aiProcess_GenNormals	|
		aiProcess_GenUVCoords	|
		(leftHanded ? aiProcess_ConvertToLeftHanded : 0));

	if (pScene) {
		m_pScene = pScene;
		return true;
	}

	std::cout << m_pImporter->GetErrorString() << "\n";
	return false;
}

void ModelImporter::extractMeshes(Mesh& aOutMesh) {
	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return;
	}

	for (U32 m = 0u; m < m_pScene->mNumMeshes; ++m) {
		aiMesh* inMesh = m_pScene->mMeshes[m];
		extractVertex(inMesh, aOutMesh);
	}
}

void ModelImporter::extractSkeletalMeshes(SkeletalMesh & aOutMesh) {
}

void ModelImporter::extractMaterials(Material& aOutMat) {

}

void ModelImporter::extractVertex(aiMesh* inMesh, Mesh& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.vertices.emplace_back(Vertex{ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])),
			*reinterpret_cast<math::Vec3f*>(&(inMesh->mNormals[i])),
			*reinterpret_cast<math::Vec2f*>(&(inMesh->mTextureCoords[i])) });
	}
}

void ModelImporter::extractSkeletalVertex(aiMesh * inMesh, SkeletalMesh & outMesh) {
}

template<typename MeshType>
void ModelImporter::AddIndices(aiMesh * inMesh, MeshType& outMesh) {
	for (U32 f = 0u; f < inMesh->mNumFaces; ++f) {
		const aiFace& inFace = inMesh->mFaces[f];
		if (inFace.mNumIndices == 3u) {
			outMesh.addTriangleIndices(
				inFace.mIndices[0],
				inFace.mIndices[1],
				inFace.mIndices[2]);
		}
	}
}

} // namespace tools
} // namespace drak