#include <memory.h>
#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLVertexAttrib.hpp>

using namespace drak::math;
using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

const GLVertexAttribDesc g_VertexAttribDescArray[] = {
	{ VERT_ATTR_POS,	0,	GL_FLOAT, 3, GL_FALSE },
	{ VERT_ATTR_NORMAL,	12, GL_FLOAT, 3, GL_FALSE },
	{ VERT_ATTR_UV,		24, GL_FLOAT, 2, GL_FALSE },
};

GLVertexAttribDesc::GLVertexAttribDesc(
	VertexAttrib	attrib,
	GLuint			offset,
	GLenum			type,
	GLint			size,
	GLboolean		normalized)
:	attrib(attrib), offset(offset), type(type), size(size), normalized(normalized) {
}

} // namespace gl
} // namespace gfx
} // namespace drak