#version 330 core
out vec4 FragColor;

in vec3 vertPos;

void main()
{
    FragColor = vec4(abs(vertPos), 1.0);
}