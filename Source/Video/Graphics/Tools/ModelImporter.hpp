#pragma once

namespace drak {
namespace gfx {
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

	bool importFromFile(const std::string& filename);
};

} // namespace tools
} // namespace gfx
} // namespace drak