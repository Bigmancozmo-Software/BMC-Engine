#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

// Output variables //
out vec3 color;
out vec2 tex;

// Uniform Variables //
uniform float scale;

void main()
{
    gl_Position = vec4(aPos * scale, 1.0);
    color = aColor;
    tex = aTex;
}