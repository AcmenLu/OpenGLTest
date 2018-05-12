#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform float ambientStrength;
uniform vec3 ambientLightColor;

uniform vec3 diffuseLightPos;
uniform vec3 diffuseLightColor;
uniform vec3 objectColor;

uniform vec3 viewPos;
uniform float specularStrength;

void main()
{
	vec3 ambient = ambientLightColor * ambientStrength;

	vec3 norm = normalize(Normal);
	vec3 ligDir = normalize(diffuseLightPos - FragPos);
	float diff = max(dot(Normal, ligDir), 0.0);
	vec3 diffuse = diffuseLightColor * diff;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-ligDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * diffuseLightPos;

	vec3 result = (ambient + diffuse) * objectColor;
	FragColor = vec4( result, 1.0 );
}