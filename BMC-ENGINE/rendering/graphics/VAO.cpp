#include "VAO.h"

VAO::VAO(GLfloat verts[], int length)
{
	glGenVertexArrays(1, &id);

	for (int i = 0; i < length; i++) // copy array
		vertices[i] = verts[i];
}
