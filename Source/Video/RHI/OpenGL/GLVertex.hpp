#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

struct GLVertex {
	GLVertex(const float p[3], const float c[4]) {
		pos[0] = p[0]; pos[1] = p[1]; pos[2] = p[2];
		color[0] = c[0]; color[1] = c[1]; color[2] = c[2]; color[3] = c[3];
	}

	GLfloat		pos[3];
	GLfloat		color[4];
};

/*
struct GLVertex {
	GLfloat		pos		[3];
	GLfloat		color	[4];
	GLfloat		normal	[3];
	GLfloat		uv		[2];
};
*/

enum GLVertexAttrib : GLuint {
	GL_VERT_ATTR_POS, 
	GL_VERT_ATTR_COLOR,
	GL_VERT_ATTR_NORMAL,
	GL_VERT_ATTR_UV
};

struct GLVertexAttribDesc {
	GLVertexAttrib	attrib;
	GLuint offset;
	GLenum type;
	GLint size;
	GLboolean normalized;
};

} // namespace gl
} // namespace video
} // namespace drak