#pragma once

#include <string>
#include <Converter/ResourceDefinitions.hpp>

#pragma region Assimp Forward Declarations
namespace Assimp {
class Importer;
} // namespace Assimp

struct aiScene;
struct aiMesh;
#pragma endregion

namespace drak {
namespace tools {
/*!
* \class ModelImporter
* \ingroup Tools
* \brief
*/
class ModelImporter final {
public:
	ModelImporter();
	~ModelImporter();

	bool startImport(const std::string& filename, bool leftHanded = false);

	void extractMeshes(Mesh& aOutMesh);
	void extractSkeletalMeshes(SkeletalMesh& aOutMesh);
	void extractMaterials(Material& aOutMat);

private:
	void extractVertex(aiMesh* inMesh, Mesh& outMesh);
	void extractSkeletalVertex(aiMesh* inMesh, SkeletalMesh& outMesh);

	template<typename MeshType>
	void AddIndices(aiMesh* inMesh, MeshType& outMesh);

private:
	Assimp::Importer*	m_pImporter;
	const aiScene*		m_pScene;
};

} // namespace tools
} // namespace gfx
} // namespace drak