#include <PrecompiledHeader/pch.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


namespace drak {
namespace gfx {
namespace tools {

ModelLoader::ModelLoader() {

}

ModelLoader::~ModelLoader() {

}

bool ModelLoader::loadFromFile(const std::string& filepath) {
	Assimp::Importer importer;
	const aiScene* pScene = importer.ReadFile(
		filepath,
		aiProcess_JoinIdenticalVertices |
		aiProcess_Triangulate |
		aiProcess_SortByPType |
		aiProcess_GenNormals);

	if (pScene) {
		// std::cout << "# meshes: " << pScene->mNumMeshes << "\n";
		// std::cout << "# materials: " << pScene->mNumMaterials << "\n";

		return true;
	}

	std::cout << importer.GetErrorString() << "\n";
	return false;
}

} // namespace tools
} // namespace gfx
} // namespace drak