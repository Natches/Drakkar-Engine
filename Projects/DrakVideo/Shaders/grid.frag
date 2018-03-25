#version 450 core

layout(binding = 0)
uniform sampler2D 	tex;
uniform vec3 		tint 		= {0.f, 1.f, 0.f};

uniform float 		nearZ 		= 0.1f; 
uniform float 		farZ  		= 100.f; 

in VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

out vec4 fragColor;

void main()
{        
	vec4 texColor = texture(tex, frag.uv);
	if (texColor.rgb == vec3(0.f, 0.f, 0.f))
		discard;
	
    fragColor = texColor * vec4(tint, 1.f);
	fragColor.a *= 0.25f;
}