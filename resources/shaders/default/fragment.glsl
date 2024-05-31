// default/fragment.glsl
#version 330 core

// Output variables //
out vec4 FragColor;

// Input Variables //
in vec3 color;
in vec2 tex;

// Uniforms //
uniform sampler2D tex0;
uniform vec4 lightColor;

void main()
{
    FragColor = texture(tex0, tex) * vec4(color / 255, 1.0) * lightColor;
}