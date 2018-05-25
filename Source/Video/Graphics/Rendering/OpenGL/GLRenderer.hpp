#pragma once

#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLRenderer
* \ingroup Graphics
* \brief
*
*/
class GLRenderer final : public IRenderer {
	DK_NONMOVABLE_NONCOPYABLE(GLRenderer)
public:
	GLRenderer() = default;
	~GLRenderer() = default;

public:
	bool init() override;
	void info() override;

	void clear() override;
	void clearColorValue(const Color3& k) override;
	void clearColorValue(const Color4& k) override;
	void clearDepthValue(F32 depth) override;

	void depthTest(bool on, EDepthMode mode) override;
	void blendTest(bool on, EBlendMode srcFactor,EBlendMode dstFactor) override;
	void cullTest(bool on, ECullMode mode) override;
	void windingOrder(EWindingOrder order) override;

	void multisampling(bool on) override;

	//void bindFrameBuffer() override;
	void bindWindowFrameBuffer() override;

private:
	static void debugLog(
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
