#include "EBO.h"

EBO::EBO(GLuint* inds, int length) : size(length)
{
	glGenBuffers(1, &id);
	indices = inds;

}

void EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void EBO::cleanup()
{
	glDeleteBuffers(1, &id);
}
