#version 330 core

layout (location = 0) in vec3 aPos; // First vec3 in vertex data

// Output variables //
out vec3 vertPos;

// Uniform Variables //
uniform float scale;

void main()
{
    gl_Position = vec4(aPos * scale, 1.0);
    vertPos = aPos; // send vertex position to fragment shader
}