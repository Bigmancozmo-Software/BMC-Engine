#include "VBO.h"

VBO::VBO(GLfloat verts[])
{
	glGenBuffers(1, &id);
}
