#version 450 core

layout(binding = 0)
uniform sampler2D 	tex;
uniform vec4 		tint 		= {1.f, 1.f, 1.f, 1.f};

uniform float 		nearZ 		= 0.1f; 
uniform float 		farZ  		= 100.f; 

in VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

out vec4 fragColor;

void main() {        
	vec4 texColor = texture(tex, frag.uv);
	fragColor = texColor * tint;
}