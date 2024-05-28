#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &id);
}

void VAO::bind()
{
	glBindVertexArray(id);
}

void VAO::cleanup()
{
	glDeleteVertexArrays(1, &id);
}
