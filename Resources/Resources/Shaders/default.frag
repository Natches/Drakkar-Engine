#version 450 core

layout(binding = 0)
uniform sampler2D 	tex;
uniform vec3 		albedo 		= {1.f, 1.f, 1.f};

uniform float 		nearZ 		= 0.1f; 
uniform float 		farZ  		= 100.f; 

uniform vec3		lightPos	= {-1.f, 1.f, -1.f};
uniform vec3		lightColor	= {1.f, 1.f, 1.f};

uniform vec3		ambient		= {0.18f, 0.18f, 0.18f};

in VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag;

out vec4 fragColor;

void main()
{     
	vec3 normal		= normalize(frag.normal);
	vec3 lightDir	= normalize(lightPos - frag.pos);
	vec3 diffuse	= max(dot(normal, lightDir), 0.0) * lightColor;

	fragColor		= vec4(albedo * (ambient + diffuse), 1.f);

    //fragColor = texture(tex, frag.uv);
}