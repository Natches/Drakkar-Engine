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
	using TexVec = std::vector<Texture>;
	using MatVec = std::vector<Material>;
	using ModelVec = std::vector<Model<Mesh>>;
	using SkelMeshVec = std::vector<Model<SkeletalMesh>>;
public:
	ModelImporter();
	~ModelImporter();

	bool startImport(const std::string& filename, bool optimizeMesh = false, bool leftHanded = false);

	void importModel(ModelVec& aModels, MatVec& aMaterials, TexVec& aTextures,
		bool extractMaterialsAndTexture = true);
	void importSkeletalModel(SkelMeshVec& aModels, MatVec& aMaterials, TexVec& aTextures,
		bool extractMaterialsAndTexture = true);

	DK_GETTER_REF_C(std::string, filename, m_filename)

private:
	void extractModels(ModelVec& aOutModelVec);
	void extractSkeletalModels(SkelMeshVec& aOutMeshVec);
	void extractMaterials(MatVec& aOutMatVec);
	void extractTextures(TexVec& aOutTexVec);
	void extractVertex(aiMesh* inMesh, Mesh& outMesh);
	void extractSkeletalVertex(aiMesh* inMesh, SkeletalMesh& outMesh);

	template<typename MeshType>
	void AddIndices(aiMesh* inMesh, MeshType& outMesh);

private:
	Assimp::Importer*	m_pImporter;
	const aiScene*		m_pScene;
	std::vector<std::tuple<std::string&>> m_textureToLoadLater;
	std::string m_filename;
};

void loadTextureFromFile(const std::string& filename, Texture& aOutTexture);

} // namespace tools
} // namespace drak