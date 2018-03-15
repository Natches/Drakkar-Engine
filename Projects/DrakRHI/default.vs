#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 color;

out VS_OUT {
	vec4 color;
} vert;


void main()
{
	vert.color = color;
	gl_Position = vec4(pos, 1.0f);
}