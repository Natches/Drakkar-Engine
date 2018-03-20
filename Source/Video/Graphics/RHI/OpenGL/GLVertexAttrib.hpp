#pragma once

#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

struct GLVertexAttribDesc {
	GLVertexAttribDesc() = default;
	GLVertexAttribDesc(
		geom::VertexAttrib	attrib,
		GLuint				offset,
		GLenum				type,
		GLint				size,
		GLboolean			normalized);

	geom::VertexAttrib	attrib;
	GLuint				offset;
	GLenum				type;
	GLint				size;
	GLboolean			normalized;
};

extern const GLVertexAttribDesc g_VertexAttribDescArray[];

} // namespace gl
} // namespace video
} // namespace drak