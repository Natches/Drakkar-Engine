#pragma once

#include <string>

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>
#include <Video/Graphics/RHI/OpenGL/GLObject.hpp>

namespace drak {
namespace video {
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
} // namespace video
} // namespace drak