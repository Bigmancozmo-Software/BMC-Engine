#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"

#include <iostream>

class VBO {
public:
	GLuint id;
	VBO(GLfloat* verts, int length);

	void bind();
	void cleanup();
private:
	GLfloat* vertices;
	int size;
};

#endif // VBO_H