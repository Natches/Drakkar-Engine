#version 450 core

precision mediump float;

//-----------------------------------------------------------------------
//	[CAMERA PROPERTIES]

uniform float 		nearZ 			= 0.1f; 
uniform float 		farZ  			= 100.f; 
uniform vec2		viewport		= {1600.f, 900.f};

//-----------------------------------------------------------------------
//	[MATERIAL PROPERTIES]

layout(binding = 0)
uniform sampler2D 	tex;

uniform vec3		ambientColor	= {0.2f, 0.2f, 0.2f};
uniform vec3		diffuseColor	= {0.8f, 0.8f, 0.8f};
uniform vec3		specularColor	= {1.f, 1.f, 1.f};

uniform float		opacity			= 1.f;
uniform float		shininess		= 16.f;

//-----------------------------------------------------------------------
//	[SCENE LIGHTS]

uniform vec3		lightColor		= {1.f, 1.f, 1.f};
uniform vec3		lightDir		= {1.f, -1.f, 1.f};
uniform float		lightPower		= 1.f;

//-----------------------------------------------------------------------
//	[OUTPUTS & INPUTS]

in VS_OUT {
	vec3 pos;
	vec3 normal;
	vec2 uv;
} vert; //======================================== [VERTEX SHADER OUTPUT]

out vec4 fragColor;	//===================================== [FINAL COLOR]

//-----------------------------------------------------------------------

void main() {     
	vec3	normal		= normalize(vert.normal);
	vec3	nLightDir	= normalize(lightDir); 

	float	lambertian	= max(dot(nLightDir, normal), 0.0);
	float	specular	= 0.f;

	if (lambertian > 0.f) {
		vec3	viewDir		= normalize(-vert.pos);
		vec3	halfDir		= normalize(nLightDir + viewDir);
		float	specAngle	= max(dot(halfDir, normal), 0.0);
		specular			= pow(specAngle, shininess);

	}

	fragColor = vec4(
		ambientColor	+ 
		diffuseColor	* lambertian * lightColor * lightPower +
		specularColor	* specular	 * lightColor * lightPower, 1.f);

	//fragColor			= vec4(albedo * (ambientColor + diffuse), 1.f);
    //fragColor = texture(tex, frag.uv);
}