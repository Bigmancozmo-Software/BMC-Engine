// default/vertex.glsl
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

// Output variables //
out vec3 color;
out vec2 tex;
out vec3 normal;
out vec3 currentPos;

// Uniform Variables //
uniform float scale;
uniform mat4 camMatrix;
uniform mat4 model;

void main()
{
    currentPos = vec3(model * vec4(aPos * scale, 1.0f));

    gl_Position = camMatrix * vec4(currentPos, 1.0);
    color = aColor;
    tex = aTex;
    normal = aPos;
}