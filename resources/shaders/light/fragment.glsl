// light/fragment.glsl
#version 330 core

// Output variables //
out vec4 FragColor;

// Uniforms //
uniform vec4 lightColor;

void main()
{
    FragColor = lightColor;
}