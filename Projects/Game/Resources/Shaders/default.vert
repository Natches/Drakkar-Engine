#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

uniform mat4 model;
uniform mat4 viewPrsp;

out VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

void main()
{
	frag.pos	= vec3(model * vec4(pos, 1.0));
	frag.normal	= normal;
	frag.uv		= uv;

	gl_Position	= viewPrsp * model * vec4(pos, 1.0);
}