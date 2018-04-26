#pragma once

#pragma region Assimp Forward Declarations
namespace Assimp {
class Importer;
} // namespace Assimp
struct aiScene;
#pragma endregion

namespace drak {
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
	void extractMeshes();
	void extractMaterials();

private:

private:
	Assimp::Importer	m_importer;
	const aiScene*		m_pScene;
};

} // namespace tools
} // namespace gfx
} // namespace drak