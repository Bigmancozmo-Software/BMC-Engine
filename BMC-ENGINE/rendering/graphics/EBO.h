#ifndef EBO_H
#define EBO_H

#include "glad/glad.h"

class EBO {
public:
	GLuint id;
	EBO(GLfloat verts[]);
};

#endif // EBO_H