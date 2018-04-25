#include <iostream> // TODO (Simon): replace with Log

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Video/Graphics/Tools/ModelImporter.hpp>

namespace drak {
namespace gfx {
namespace tools {

ModelImporter::ModelImporter() {

}

ModelImporter::~ModelImporter() {

}

bool ModelImporter::importFromFile(const std::string& filename) {
	Assimp::Importer importer;
	const aiScene* pScene = importer.ReadFile(
		filename,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate |
		aiProcess_SortByPType |
		aiProcess_GenNormals);

	if (pScene) {
		std::cout << "# meshes: " << pScene->mNumMeshes << "\n";
		std::cout << "# materials: " << pScene->mNumMaterials << "\n";
		return true;
	}

	std::cout << importer.GetErrorString() << "\n";
	return false;
}

} // namespace tools
} // namespace gfx
} // namespace drak