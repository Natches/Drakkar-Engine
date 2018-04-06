#version 450 core

in VS_OUT {
	vec2 uv;
} frag;

out vec4 fragColor;

uniform sampler2D frame;

void main()
{ 
    fragColor = texture(frame, frag.uv);
}