#pragma once

#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>

namespace drak {
namespace gfx {
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
} // namespace gfx
} // namespace drak