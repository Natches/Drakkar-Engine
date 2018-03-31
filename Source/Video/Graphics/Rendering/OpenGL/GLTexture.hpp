#pragma once

#include <string>

#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

class GLTexture final : public GLObject {
public:
	GLTexture();
	~GLTexture();

	void use() const;

	//bool loadFromData(const std::string& vertCode, 
	bool loadFromFile(const std::string& filename);

private:

};

} // namespace gl
} // namespace gfx
} // namespace drak