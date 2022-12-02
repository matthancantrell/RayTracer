#version 430 core

in vec2 texcoord;

out vec4 fcolor;

layout (binding = 0) uniform sampler2D diffuseMap;

void main()
{
    vec3 color = texture(diffuseMap, texcoord).rgb;

    // black / white
    float avg = (color.r + color.g + color.b) / 3.0;
    fcolor = vec4(vec3(avg), 1);

    // invert
    //fcolor = vec4(1.0 - color, 1);

    // "night vision"
    //float avg = (color.r + color.g + color.b) / 3.0;
    //fcolor = vec4(vec3(0, avg, 0), 1);
 
    // regular
    //fcolor = texture(diffuseMap, texcoord);
}