#include "VAO.h"

VAO::VAO(GLfloat verts[])
{
	glGenVertexArrays(1, &id);
}
