#version 450 core

//-----------------------------------------------------------------------
//	[CAMERA PROPERTIES]

uniform float 		nearZ 			= 0.1f; 
uniform float 		farZ  			= 100.f; 
uniform vec2		viewport		= {1600.f, 900.f};

//-----------------------------------------------------------------------
//	[MATERIAL PROPERTIES]

//struct Material {
//	vec3	ambientColor	= {1.f, 1.f, 1.f};
//	vec3	diffuseColor	= {0.15f, 0.15f, 0.15f};
//	float	opacity			= 1.f;
//}
//uniform Material material;

layout(binding = 0)
uniform sampler2D 	tex;

uniform float		opacity			= 1.f;

uniform vec3		ambientColor	= {1.f, 1.f, 1.f};
uniform vec3		diffuseColor	= {0.15f, 0.15f, 0.15f};

//-----------------------------------------------------------------------
//	[SCENE LIGHTS]

uniform vec3		lightPos		= {-1.f, 1.f, -1.f};
uniform vec3		lightColor		= {1.f, 1.f, 1.f};

//-----------------------------------------------------------------------
//	[OUTPUTS & INPUTS]

in VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} frag; //======================================== [VERTEX SHADER OUTPUT]

out vec4 fragColor;	//===================================== [FINAL COLOR]

//-----------------------------------------------------------------------

void main() {     
	vec3 normal			= normalize(frag.normal);
	vec3 lightDir		= normalize(lightPos - frag.pos);
	vec3 diffuse		= max(dot(normal, lightDir), 0.0) * lightColor;
	fragColor			= vec4(ambientColor * diffuse, 1.f);

    //fragColor = texture(tex, frag.uv);
}