#include "VAO.h"

VAO::VAO(GLfloat verts[])
{
	glGenVertexArrays(1, &id);

	for (int i = 0; i < 10; ++i) // copy array
		vertices[i] = verts[i];
}
