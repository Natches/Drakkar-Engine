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
} vert;

void main()
{
	vert.pos	= vec3(model * vec4(pos, 1.0));
	vert.normal	= (viewPrsp * inverse(transpose(model)) * vec4(normal, 0.f)).xyz;
	vert.uv		= uv;

	gl_Position	= viewPrsp * model * vec4(pos, 1.0);
}