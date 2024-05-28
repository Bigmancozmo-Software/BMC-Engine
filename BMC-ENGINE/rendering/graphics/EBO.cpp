#include "EBO.h"

EBO::EBO(GLuint inds[], int length)
{
	glGenBuffers(1, &id);

	for (int i = 0; i < length; i++)
		indices[i] = inds[i];

}
