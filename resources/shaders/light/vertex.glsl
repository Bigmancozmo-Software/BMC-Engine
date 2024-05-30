#version 330 core

layout (location = 0) in vec3 aPos;

// Uniform Variables //
uniform float scale;
uniform mat4 camMatrix;
uniform mat4 model;

void main()
{
    gl_Position = camMatrix * model * vec4(aPos * scale, 1.0);
}