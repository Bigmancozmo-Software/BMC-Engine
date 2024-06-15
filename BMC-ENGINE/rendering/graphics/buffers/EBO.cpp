#include "EBO.h"

EBO::EBO(GLuint* inds, int length) : size(length)
{
	glGenBuffers(1, &id);
	indices = inds;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::cleanup()
{
	glDeleteBuffers(1, &id);
}
