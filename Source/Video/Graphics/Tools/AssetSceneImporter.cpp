#include <iostream> // TODO (Simon): replace with Log

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
	if (m_pScene) {
		for (U32 m = 0u; m < m_pScene->mNumMeshes; ++m) {
			aiMesh* inMesh = m_pScene->mMeshes[m];
			Mesh	outMesh;

			for (U32 v = 0u; v < inMesh->mNumVertices; ++v) {
				
				Vertex vert;
				
				outMesh.addTriangleVertices()
				inMesh->mVertices[v].x
				inMesh->mVertices[v].y
				inMesh->mVertices[v].z
			}
			
			/*inMesh->mVertices[0].x
			inMesh->mVertices[0].y
			inMesh->mVertices[0].z

			inMesh->mNormals[0].x
			inMesh->mNormals[0].y
			inMesh->mNormals[0].z

			inMesh->mTextureCoords[0].x
			inMesh->mTextureCoords[0].y*/

			for (U32 f = 0u; f < inMesh->mNumFaces; ++f) {
				const aiFace& inFace = inMesh->mFaces[f];
				if (inFace.mNumIndices == 3u)
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