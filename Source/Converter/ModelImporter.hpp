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
namespace importer{
/*!
* \class ModelImporter
* \ingroup Tools
* \brief
*/
class ModelImporter final {
	using TexVec = std::vector<definition::Texture>;
	using MatVec = std::vector<definition::Material>;
	using ModelVec = std::vector<definition::Model>;
	using MeshVec = std::vector<definition::Mesh>;
	using SkelMeshVec = std::vector<definition::SkeletalMesh>;
public:
	ModelImporter();
	ModelImporter(const ModelImporter& m);
	ModelImporter(ModelImporter&& m);
	~ModelImporter();

	ModelImporter& operator=(const ModelImporter& m);
	ModelImporter& operator=(ModelImporter&& m);

	bool operator==(const ModelImporter& m);

	bool startImport(const std::string& filename, bool optimizeMesh = false, bool leftHanded = false);

	void importModel(ModelVec& aModels, MeshVec& aMeshes, MatVec& aMaterials, TexVec& aTextures,
		bool extractMaterialsAndTexture = true);

	void importSkeletalModel(ModelVec& aModels, SkelMeshVec& aSkelMeshes, MatVec& aMaterials, TexVec& aTextures,
		bool extractMaterialsAndTexture = true);

	DK_GETTER_REF_C(std::string, filename, m_filename)

private:
	void extractMeshes(ModelVec& aOutModelVec, MeshVec& aOutMeshVec);
	void extractSkeletalMeshes(ModelVec& aOutModelVec, SkelMeshVec& aOutMeshVec);
	void extractMaterials(MatVec& aOutMatVec);
	void extractTextures(TexVec& aOutTexVec);
	void extractVertex(aiMesh* inMesh, definition::Mesh& outMesh);
	void extractSkeletalVertex(aiMesh* inMesh, definition::SkeletalMesh& outMesh);

	template<typename MeshType>
	void AddIndices(aiMesh* inMesh, MeshType& outMesh);

private:
	Assimp::Importer*	m_pImporter;
	const aiScene*		m_pScene;
	std::vector<std::tuple<std::string&>> m_textureToLoadLater;
	std::string m_filename;
};

void loadTextureFromFile(const std::string& filename, definition::Texture& aOutTexture);

} // namespace importer
} // namespace tools
} // namespace drak