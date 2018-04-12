#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

class GLTexture final : public GLObject {
public:
	GLTexture();
	~GLTexture();

	void bind() const;
	bool loadFromFile(const char* filename, bool verticalFlip = true);
};

} // namespace gl
} // namespace gfx
} // namespace drak