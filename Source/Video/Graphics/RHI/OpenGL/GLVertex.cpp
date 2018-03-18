#include <memory.h>
#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertex.hpp>

using namespace drak::math;

namespace drak {
namespace video {
namespace gl {

GLVertex::GLVertex(
	const Vec3f& aPos,
	const Vec3f& aNormal,
	const Vec2f& aUV) 
:	pos(aPos), normal(aNormal), uv(aUV) {
}

const GLVertexAttribDesc g_VertexAttribDescArray[] = {
	{ GL_VERT_ATTR_POS,		0,	GL_FLOAT, 3, GL_FALSE },
	{ GL_VERT_ATTR_NORMAL,	28, GL_FLOAT, 3, GL_TRUE  },
	{ GL_VERT_ATTR_UV,		40, GL_FLOAT, 2, GL_FALSE },
};

GLVertexAttribDesc::GLVertexAttribDesc(
	GLVertexAttrib	attrib,
	GLuint			offset,
	GLenum			type,
	GLint			size,
	GLboolean		normalized)
:	attrib(attrib), offset(offset), type(type), size(size), normalized(normalized) {
}

} // namespace gl
} // namespace video
} // namespace drak