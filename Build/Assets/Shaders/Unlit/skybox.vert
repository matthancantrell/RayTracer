#version 430 core 
in layout(location = 0) vec3 vposition; // 0

out vec3 texcoord;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	//color = vcolor;
	texcoord = vposition;

	mat4 vp = projection * mat4(mat3(view));

	gl_Position = vp * vec4(vposition, 1.0);
}
