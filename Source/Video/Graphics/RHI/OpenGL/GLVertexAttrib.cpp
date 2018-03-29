#include <memory.h>
#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertexAttrib.hpp>

using namespace drak::math;
using namespace drak::video::geom;

namespace drak {
namespace video {
namespace gl {

const GLVertexAttribDesc g_VertexAttribDescArray[] = {
	{ VERT_ATTR_POS,	0,	GL_FLOAT, 3, GL_FALSE },
	{ VERT_ATTR_NORMAL,	28, GL_FLOAT, 3, GL_TRUE  },
	{ VERT_ATTR_UV,		40, GL_FLOAT, 2, GL_FALSE },
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
} // namespace video
} // namespace drak