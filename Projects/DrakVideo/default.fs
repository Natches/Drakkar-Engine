#version 450 core

uniform vec4 	tint 	= {0.f, 1.f, 0.f, 1.f};
uniform float 	nearZ 	= 0.1f; 
uniform float 	farZ  	= 100.f; 

in FS_IN {
	vec3 pos;
	vec3 normal;
	vec3 uv;
} frag;

out vec4 fragColor;

void main()
{             
    fragColor = tint;
}