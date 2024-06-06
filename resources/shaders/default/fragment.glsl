// default/fragment.glsl
#version 330 core

// Output variables //
out vec4 FragColor;

// Input Variables //
in vec3 color;
in vec2 tex;

in vec3 normal;
in vec3 currentPos;

// Uniforms //
uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

void main()
{
    float ambient = 0.2f;

    vec3 _normal = normalize(normal);
    vec3 lightDirection = normalize(lightPos - currentPos);
    float diffuse = max(dot(_normal, lightDirection), 0.0f);

    float specularLight = 0.5f;
    vec3 viewDir = normalize(camPos - currentPos);
    vec3 reflectionDir = reflect(-lightDirection, _normal);
    float specAmount = pow(max(dot(viewDir, reflectionDir), 0.0f), 8);
    float specular = specAmount * specularLight;

    FragColor = texture(tex0, tex) * vec4(color / 255, 1.0) * lightColor * (diffuse + ambient + specular);
}