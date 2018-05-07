#pragma once

#pragma region Assimp Forward Declarations
namespace Assimp {
class Importer;
} // namespace Assimp
struct aiScene;
#pragma endregion

namespace drak {
namespace geom {
class AMesh;
template<typename T>
class Mesh;
struct Vertex1P;
struct Vertex1P1N;
struct Vertex1P1N1UV;
} // namespace geom
namespace gfx {
namespace tools {

/*!
* \class AssetSceneImporter
* \ingroup Tools
* \brief
*/
class AssetSceneImporter final {
public:
	AssetSceneImporter();
	~AssetSceneImporter();

	bool startImport(const std::string& filename, bool leftHanded = false);

	drak::geom::AMesh* extractMeshes();
	void extractMaterials();

private:
	void extractPositions(aiMesh* inMesh, geom::Mesh<geom::Vertex1P>& outMesh);
	void extractPositionNormals(aiMesh* inMesh, geom::Mesh<geom::Vertex1P1N>& outMesh);
	void extractPositionNormalUVs(aiMesh* inMesh, geom::Mesh<geom::Vertex1P1N1UV>& outMesh);

	template<typename MeshType>
	void AddIndices(aiMesh* inMesh, MeshType& outMesh);

private:
	Assimp::Importer	m_importer;
	const aiScene*		m_pScene;
};

} // namespace tools
} // namespace gfx
} // namespace drak