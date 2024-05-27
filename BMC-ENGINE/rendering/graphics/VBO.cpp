#include "VBO.h"

VBO::VBO(GLfloat verts[])
{
	glGenBuffers(1, &id);

	for (int i = 0; i < 10; ++i) // copy array
		vertices[i] = verts[i];
}
