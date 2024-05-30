#ifndef GENERATOR_H
#define GENERATOR_H

#include <glad/glad.h>

class CubeGenerator {
public:
	static void vertices(GLfloat verts[], float size);
	static GLfloat* indices(float size);
};

#endif