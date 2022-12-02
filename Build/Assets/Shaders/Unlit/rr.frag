#version 430 core

//in vec3 color;
in vec3 refraction_dir;
in vec3 reflection_dir;

out vec4 fcolor;

uniform float interpolation = 1.0f;

layout (binding = 0) uniform samplerCube cubeMap;


void main()
{
	vec3 reflect_color = texture(cubeMap, reflection_dir).rgb;
	vec3 refraction_color = texture(cubeMap, refraction_dir).rgb;

	vec3 color = mix(reflect_color, refraction_color, interpolation);
	fcolor = texture(cubeMap, color);
}
