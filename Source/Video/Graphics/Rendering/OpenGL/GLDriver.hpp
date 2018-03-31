#pragma once

#include <Video/Graphics/Rendering/Base/IGraphicsDriver.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLDriver
* \ingroup Graphics
* \brief
*
*/
class GLDriver final : public IGraphicsDriver {
	DK_NONMOVABLE_NONCOPYABLE(GLDriver)
public:
	GLDriver() = default;
	~GLDriver() = default;

public:
	bool init() override;
	void info() override;

	void clear() override;
	void clearColorValue(const Color3& color) override;
	void clearColorValue(const Color4& color) override;
	void clearDepthValue(F32 depth) override;

	void depthTest(bool on, EDepthMode mode = EDepthMode::LESS) override;

	void blendTest(bool on, 
		EBlendMode srcFactor = EBlendMode::SRC_ALPHA,
		EBlendMode dstFactor = EBlendMode::ONE_MINUS_SRC_ALPHA) override;

	void cullTest(bool on, ECullMode mode = ECullMode::BACK) override;
	void windingOrder(EWindingOrder order) override;

private:
	static void errorCallback(
		GLenum			source,
		GLenum			type,
		GLuint			id,
		GLenum			severity,
		GLsizei			length,
		const GLchar*	message,
		const GLvoid*	userParam);
};

} // namespace gl
} // namespace gfx
} // namespace drak
