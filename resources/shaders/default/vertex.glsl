#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 vertPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    vertPos = aPos; // send vertex position to fragment shader
}