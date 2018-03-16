#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>
#include <Video/RHI/OpenGL/GLVertexArray.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLMesh
* \ingroup DrakVideo
* \brief
*
*/
class GLMesh final
{
public:
	GLMesh()	= default;
	~GLMesh()	= default;


private:
	GLVertexArray m_vao;
};

} // namespace gl
} // namespace gfx
} // namespace drak
