#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
layout(location = 3) in uvec4 boneIndices;
layout(location = 4) in vec4 boneWeights;

uniform mat4 model;
uniform mat4 viewPrsp;

layout(binding = 0, std430) buffer SkinningInfo {
	mat4 boneTransform[];
} skinInfo;

out VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

void main()
{
	vec4 skinPos =  boneWeights.x * (skinInfo.boneTransform[boneIndices.x] * vec4(pos, 1.0f)) +
					boneWeights.y * (skinInfo.boneTransform[boneIndices.y] * vec4(pos, 1.0f)) +
					boneWeights.z * (skinInfo.boneTransform[boneIndices.z] * vec4(pos, 1.0f)) +
					boneWeights.w * (skinInfo.boneTransform[boneIndices.w] * vec4(pos, 1.0f));

	frag.pos	= vec3(model * vec4(skinPos.xyz, 1.0f));
	frag.normal	= normal;
	frag.uv		= uv;

	gl_Position	= viewPrsp * (model * vec4(skinPos.xyz, 1.0f));
}