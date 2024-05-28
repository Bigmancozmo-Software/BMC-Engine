#include "VBO.h"

VBO::VBO(GLfloat verts[], int length)
{
	glGenBuffers(1, &id);

	for (int i = 0; i < length; i++) // copy array
		vertices[i] = verts[i];
}
