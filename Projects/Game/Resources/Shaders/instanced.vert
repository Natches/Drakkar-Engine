#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

layout(std140, binding = 4, row_major) uniform modelBlock {
	mat4 models[1024];
};

uniform mat4 viewPrsp;

out VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

void main()
{
	frag.pos	= vec3(models[gl_InstanceID] * vec4(pos, 1.f));
	frag.normal	= mat3(transpose(inverse(models[gl_InstanceID]))) * normal;
	frag.uv		= uv;

	gl_Position	= viewPrsp * models[gl_InstanceID] * vec4(pos, 1.f);
}