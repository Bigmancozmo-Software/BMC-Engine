// default/fragment.glsl
#version 330 core

// Output variables //
out vec4 FragColor;

// Input Variables //
in vec3 color;
in vec2 tex;

uniform sampler2D tex0;

void main()
{
    FragColor = texture(tex0, tex) * vec4(color / 255, 1.0);
}