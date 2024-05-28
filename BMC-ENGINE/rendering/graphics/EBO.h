#ifndef EBO_H
#define EBO_H

#include "glad/glad.h"

#include <iostream>

class EBO {
public:
	GLuint id;
	EBO(GLuint* inds, int length);

	void bind();
	void cleanup();
private:
	GLuint* indices;
	int size;
};

#endif // EBO_H