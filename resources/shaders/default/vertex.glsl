#version 330 core

layout (location = 0) in vec3 aPos; // First vec3 in vertex data
layout (location = 1) in vec3 aColor;

// Output variables //
out vec3 color;

// Uniform Variables //
uniform float scale;

void main()
{
    gl_Position = vec4(aPos * scale, 1.0);
    color = aColor; // send provided color to fragment shader
}