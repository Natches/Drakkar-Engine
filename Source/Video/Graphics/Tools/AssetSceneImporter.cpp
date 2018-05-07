#include <PrecompiledHeader/pch.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace tools {

AssetSceneImporter::AssetSceneImporter()
:	m_pScene(nullptr), m_pImporter(new Assimp::Importer) {
}

AssetSceneImporter::~AssetSceneImporter() {
	delete m_pImporter;
}

bool AssetSceneImporter::startImport(const std::string& filename, bool leftHanded) {
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

AMesh* AssetSceneImporter::extractMeshes() {
	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return nullptr;
	}

	for (U32 m = 0u; m < m_pScene->mNumMeshes; ++m) {
		aiMesh* inMesh = m_pScene->mMeshes[m];
		if (!inMesh->HasNormals() && !inMesh->HasTextureCoords(0u)) {
			Mesh<Vertex1P>*	outMesh = new Mesh<Vertex1P>();
			extractPositions(inMesh, *outMesh);
			return outMesh;
		}
		else if (inMesh->HasNormals() && !inMesh->HasTextureCoords(0u)) {
			Mesh<Vertex1P1N>* outMesh = new Mesh<Vertex1P1N>();
			extractPositionNormals(inMesh, *outMesh);
			return outMesh;
		}
		else {
			Mesh<Vertex1P1N1UV>* outMesh = new Mesh<Vertex1P1N1UV>();
			extractPositionNormalUVs(inMesh, *outMesh);
			return outMesh;
		}
	}
	return nullptr;
}

void AssetSceneImporter::extractMaterials() {

}

void AssetSceneImporter::extractPositions(aiMesh* inMesh, Mesh<Vertex1P>& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.addVertex({ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])) });
	}
}

void AssetSceneImporter::extractPositionNormals(aiMesh* inMesh, Mesh<Vertex1P1N>& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.addVertex({ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])),
			*reinterpret_cast<math::Vec3f*>(&(inMesh->mNormals[i])) });
	}
}

void AssetSceneImporter::extractPositionNormalUVs(aiMesh* inMesh, Mesh<Vertex1P1N1UV>& outMesh) {
	for (unsigned i = 0, size = inMesh->mNumVertices - 1; i < size; ++i) {
		outMesh.addVertex({ *reinterpret_cast<math::Vec3f*>(&(inMesh->mVertices[i])),
			*reinterpret_cast<math::Vec3f*>(&(inMesh->mNormals[i])),
			*reinterpret_cast<math::Vec2f*>(&(inMesh->mTextureCoords[i])) });
	}
}

template<typename MeshType>
void AssetSceneImporter::AddIndices(aiMesh * inMesh, MeshType& outMesh) {
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
} // namespace gfx
} // namespace drak