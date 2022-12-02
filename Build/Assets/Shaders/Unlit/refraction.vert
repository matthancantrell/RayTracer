#version 430 core 
in layout(location = 0) vec3 vposition; // 0
in layout(location = 2) vec3 vnormal;

out vec3 refraction_dir;
uniform float ri = 1.0;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	//color = vcolor;
	vec3 position = vec3(model * vec4(vposition, 1));
	vec3 normal = normalize(mat3(model) * vnormal);

	vec3 camera_position = vec3(inverse(view)[3]);
	vec3 view_dir = normalize(position - camera_position);
	refraction_dir = refract(view_dir, normal, ri);

	mat4 mvp = projection * view * model;

	gl_Position = mvp * vec4(vposition, 1.0);
}
