#version 430 core

//in vec3 color;
in vec3 ref_dir;

out vec4 fcolor;

layout (binding = 0) uniform samplerCube cubeMap;


void main()
{
	fcolor = texture(cubeMap, ref_dir);
}
