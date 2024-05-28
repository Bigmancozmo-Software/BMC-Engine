#ifndef EBO_H
#define EBO_H

#include "glad/glad.h"
#include <iostream>
class EBO {
public:
	GLuint id;
	EBO(GLuint inds[], int length);
private:
	GLuint indices[];
};

#endif // EBO_H