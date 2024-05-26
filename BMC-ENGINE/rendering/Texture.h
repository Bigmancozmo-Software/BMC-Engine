#pragma once

#include <glad/glad.h>
#include "shaders/Shader.h"
#include "stb_image.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
	~Texture();

	void texUnit(Shader* shader, const char* uniform, GLuint unit);
	void bind();
	void unbind();
};