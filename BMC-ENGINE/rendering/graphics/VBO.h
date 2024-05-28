#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"

#include <iostream>

class VBO {
public:
	GLuint id;
	VBO(GLfloat verts[], int length);
private:
	GLfloat vertices[];
};

#endif // VBO_H