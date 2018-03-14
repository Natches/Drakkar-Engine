#pragma once

#include <Core/Types.hpp>

namespace drak {
namespace video {
namespace gl {

using GLbyte        = I8;
using GLshort       = I16;
using GLint			= I32;
using GLsizei       = I32;

using GLboolean     = U8;
using GLubyte       = U8;
using GLushort      = U16;
using GLenum        = U32;
using GLbitfield    = U32;
using GLuint        = U32;

using GLulong       = UL32;

using GLfloat       = F32;
using GLclampf      = F32;
using GLdouble      = F64;
using GLclampd		= F64;

using GLchar		= char;
using GLvoid		= void;

//--------------------------------------------------------------------------------------------

struct GLVertex {
	GLfloat		position	[4];
	GLubyte		color		[4];
	GLfloat		normal		[3];
	GLclampf	texcoords	[2];
};

} // namespace gl
} // namespace gfx
} // namespace drak