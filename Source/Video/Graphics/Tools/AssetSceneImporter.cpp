#include <iostream> // TODO (Simon): replace with Log and modify debug message code

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Core/Engine/Types.hpp>
#include <Video/Graphics/Tools/AssetSceneImporter.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace tools {

AssetSceneImporter::AssetSceneImporter()
:	m_pScene(nullptr) {

}

AssetSceneImporter::~AssetSceneImporter() {

}

bool AssetSceneImporter::startImport(const std::string& filename, bool leftHanded) {
	const aiScene* pScene = m_importer.ReadFile(
		filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate	|
		aiProcess_SortByPType	|
		aiProcess_GenNormals	| 
		aiProcess_GenUVCoords	|
		leftHanded ? aiProcess_ConvertToLeftHanded : 0);

	if (pScene) {
		m_pScene = pScene;
		return true;
	}
	
	std::cout << m_importer.GetErrorString() << "\n";
	return false;
}

void AssetSceneImporter::extractMeshes() {
	if (m_pScene == nullptr) {
		std::cout << "AssetSceneImporter: Please load a valid asset scene first\n";
		return;
	}

	for (U32 m = 0u; m < m_pScene->mNumMeshes; ++m) {
		aiMesh* inMesh = m_pScene->mMeshes[m];
		Mesh	outMesh;

		std::vector<math::Vec3f> positions;
		positions.insert(
			positions.end(),
			&inMesh->mVertices[0],
			&inMesh->mVertices[inMesh->mNumVertices - 1]);
		

		if (inMesh->HasNormals()) {
			std::vector<math::Vec3f> normals;
			normals.insert(
				normals.end(),
				&inMesh->mVertices[0],
				&inMesh->mVertices[inMesh->mNumVertices - 1]);
		}

		if (inMesh->HasTextureCoords(0u)) {
			std::vector<math::Vec2f> texCoords;
			texCoords.insert(
				texCoords.end(),
				&inMesh->mVertices[0],
				&inMesh->mVertices[inMesh->mNumVertices - 1]);
		}
	
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
	
}

void AssetSceneImporter::extractMaterials() {

}

} // namespace tools
} // namespace gfx
} // namespace drak