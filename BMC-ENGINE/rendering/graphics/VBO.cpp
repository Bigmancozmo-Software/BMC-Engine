#include "VBO.h"

VBO::VBO(GLfloat* verts, int length) : size(length) {
	glGenBuffers(1, &id);
	vertices = verts; // Just store the pointer, no need to copy
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
}

void VBO::cleanup()
{
	glDeleteBuffers(1, &id);
}
