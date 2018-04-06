#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

uniform mat4 	MVP;
uniform vec2	resolution;

out VS_OUT {
	vec2 uv;
} frag;

void main()
{
	frag.uv = uv * resolution;
	
	gl_Position = MVP * vec4(pos, 1.0f);
}