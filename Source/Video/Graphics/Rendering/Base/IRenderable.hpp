#pragma once

namespace drak {
namespace gfx {

/*!
* \class IRenderable
* \ingroup Graphics
* \brief
*
*/
class IRenderable {
public:
	IRenderable() = default;
	virtual ~IRenderable() = default;

	virtual void render() = 0;
};

using RenderArray = std::vector<IRenderable*>;

} // namespace gfx
} // namespace drak