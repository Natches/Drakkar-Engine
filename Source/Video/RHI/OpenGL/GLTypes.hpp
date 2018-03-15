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

#define DK_GET(			T, name, var)	T			name() const			{ return var; }
#define DK_GET_REF_C(	T, name, var)	const T&	name() const			{ return var; }
#define DK_GET_REF_V(	T, name, var)	T&			name()					{ return var; }

#define DK_SET(			T, name, var)	void		name(		T	val)	{ var = val; }
#define DK_SET_REF_C(	T, name, var)	void		name(const	T&	val)	{ var = val; }

//--------------------------------------------------------------------------------------------

} // namespace gl
} // namespace video
} // namespace drak