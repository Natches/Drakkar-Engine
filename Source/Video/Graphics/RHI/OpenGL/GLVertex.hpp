#pragma once

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec2.hpp>

namespace drak {
namespace video {
namespace gl {

struct GLVertex {
	GLVertex() = default;
	GLVertex(
		const math::Vec3f& aPos,
		const math::Vec3f& aNormal,
		const math::Vec2f& aUV);

	math::Vec3f pos;
	math::Vec3f normal;
	math::Vec2f uv;
};

enum GLVertexAttrib : GLuint {
	GL_VERT_ATTR_POS,
	GL_VERT_ATTR_NORMAL,
	GL_VERT_ATTR_UV,
	GL_VERT_ATTR_COUNT
};

struct GLVertexAttribDesc {
	GLVertexAttribDesc() = default;
	GLVertexAttribDesc(
		GLVertexAttrib	attrib,
		GLuint			offset,
		GLenum			type,
		GLint			size,
		GLboolean		normalized);

	GLVertexAttrib	attrib;
	GLuint			offset;
	GLenum			type;
	GLint			size;
	GLboolean		normalized;
};

extern const GLVertexAttribDesc g_VertexAttribDescArray[];

} // namespace gl
} // namespace video
} // namespace drak