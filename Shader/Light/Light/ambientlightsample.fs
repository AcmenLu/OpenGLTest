#version 330 core
out vec4 FragColor;

uniform float ambientStrength;
uniform vec3 ambientLightColor;

void main()
{
	// float ambientStrength = 0.9;
	vec3 ambient = ambientLightColor * ambientStrength;
    FragColor = vec4( ambient, 1.0 );
}