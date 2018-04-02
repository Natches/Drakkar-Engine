#pragma once

namespace drak {
namespace gfx {
namespace tools {

/*!
* \class ModelLoader
* \ingroup Tools
* \brief
*/
class ModelLoader final {
public:
	ModelLoader();
	~ModelLoader();

	bool loadFromFile(const std::string& filepath);
};

} // namespace tools
} // namespace gfx
} // namespace drak