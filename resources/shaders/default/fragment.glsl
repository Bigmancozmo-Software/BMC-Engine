#version 330 core

// Output variables //
out vec4 FragColor;

// Input Variables //
in vec3 color;

void main()
{
    FragColor = vec4(color / 255, 1.0);
}