#version 450 core

in VS_OUT 
{
	vec4 color;
} frag;

out vec4 color;

void main()
{
	color = frag.color;
}