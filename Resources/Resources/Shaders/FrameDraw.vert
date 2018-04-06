#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 uv;

out VS_OUT {
	vec2 uv;
} vert;

void main()
{
	vert.uv = uv;
    gl_Position = vec4(pos.x, pos.y, 0.0, 1.0); 
} 