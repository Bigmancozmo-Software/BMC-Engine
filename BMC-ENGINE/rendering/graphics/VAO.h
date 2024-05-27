#ifndef VAO_H
#define VAO_H

#include "glad/glad.h"

class VAO {
public:
	GLuint id;
	VAO(GLfloat verts[]);
private:
	GLfloat vertices[];
};

#endif // VAO_H