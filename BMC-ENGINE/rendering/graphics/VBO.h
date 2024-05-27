#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"

class VBO {
public:
	GLuint id;
	VBO(GLfloat verts[]);
private:
	GLfloat vertices[];
};

#endif // VBO_H