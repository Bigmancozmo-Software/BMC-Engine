#include "VAO.h"

VAO::VAO(int length)
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
