#version 450 core

out VS_OUT {
	vec2 uv;
} vert;

out vec4 fragColor;

uniform sampler2D frame;

void main()
{ 
    fragColor = texture(frame, vert.uv);
}