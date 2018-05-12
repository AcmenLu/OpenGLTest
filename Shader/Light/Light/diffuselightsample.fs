#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform float ambientStrength;
uniform vec3 ambientLightColor;

uniform vec3 diffuseLightPos;
uniform vec3 diffuseLightColor;
uniform vec3 objectColor;

void main()
{
	vec3 ambient = ambientLightColor * ambientStrength;

	vec3 norm = normalize(Normal);
	vec3 ligDir = normalize(diffuseLightPos - FragPos);
	float diff = max(dot(Normal, ligDir), 0.0);
	vec3 diffuse = diffuseLightColor * diff;

	vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4( result, 1.0 );
}