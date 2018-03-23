#version 450 core

uniform vec4 tint = {0.f, 1.f, 0.f, 1.f};

in FS_IN {
	vec3 pos;
	vec3 normal;
	vec3 uv;
} frag;

out vec4 color;

void main()
{
	color = tint;
}