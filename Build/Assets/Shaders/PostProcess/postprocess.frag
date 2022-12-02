#version 430 core

in vec2 texcoord;

out vec4 fcolor;

uniform sampler2D textureMap;

void main()
{
    vec3 color = texture(textureMap, texcoord).rgb;

    // black / white
    //float avg = (color.r + color.g + color.b) / 3.0;
    //fcolor = vec4(vec3(avg), 1);

    // invert
    //fcolor = vec4(1.0 - color, 1);

    // "night vision"
    //float avg = (color.r + color.g + color.b) / 3.0;
    //fcolor = vec4(vec3(0, avg, 0), 1);
 
    // regular
    fcolor = texture(textureMap, texcoord);
}