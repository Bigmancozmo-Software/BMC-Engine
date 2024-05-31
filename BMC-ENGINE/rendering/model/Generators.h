#ifndef GENERATOR_H
#define GENERATOR_H

#include <glad/glad.h>
#include <iostream>

class CubeGenerator {
public:
	static void vertices(GLfloat verts[], float size);
	static void indices(GLuint inds[]);
};

#endif // GENERATOR_H