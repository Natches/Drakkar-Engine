#include <GL/glew.h>
#include <Video/RHI/OpenGL/OpenGLRHI.hpp>

namespace drak {
namespace video {
namespace ogl {

#pragma region Macro Utils
#define DK_SELECT(query)		switch(query) {
#define DK_CASE(cond, line)		case cond: line; break;
#define DK_END					}
#pragma endregion

#pragma region Static Initialization
bool s_ready = false;
#pragma endregion

bool Init() {
	glewExperimental = true;
	s_ready = glewInit() == GLEW_OK;
	return s_ready;
}

void DepthMode(bool on, DepthFunc func) {
	on ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);

	DK_SELECT(func) 
		DK_CASE(DepthFunc::LESS,	glDepthFunc(GL_LESS))
		DK_CASE(DepthFunc::LEQUAL,	glDepthFunc(GL_LEQUAL))
		DK_CASE(DepthFunc::EQUAL,	glDepthFunc(GL_EQUAL))
		DK_CASE(DepthFunc::GEQUAL,	glDepthFunc(GL_GEQUAL))
		DK_CASE(DepthFunc::GREATER, glDepthFunc(GL_GREATER))
	DK_END
}

void CullMode(bool on, CullFunc func) {
	on ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);

	DK_SELECT(func)
		DK_CASE(CullFunc::FRONT, glCullFace(GL_FRONT))
		DK_CASE(CullFunc::BACK,	 glCullFace(GL_BACK))
		DK_CASE(CullFunc::BOTH,	 glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

} // namespace ogl
} // namespace gfx
} // namespace drak