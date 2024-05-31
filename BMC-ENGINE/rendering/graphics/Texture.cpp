#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType)
{
	type = texType;

	int imgWidth, imgHeight, imgChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image, &imgWidth, &imgHeight, &imgChannels, 0);

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(texType, ID);
	this->unit = slot;
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(texType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);
	glGenerateMipmap(texType);

	stbi_image_free(bytes);
	glBindTexture(texType, 0);
}

void Texture::texUnit(Shader* shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader->ID, uniform);
	shader->use();
	glUniform1i(texUni, unit);
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(type, ID);
}

void Texture::unbind()
{
	glBindTexture(type, 0);
}

void Texture::cleanup()
{
	glDeleteTextures(1, &ID);
}
