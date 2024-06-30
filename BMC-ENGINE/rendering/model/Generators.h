#ifndef GENERATOR_H
#define GENERATOR_H

#include <glad/glad.h>
#include <iostream>

class CubeGenerator {
public:
	/// 
	/// Assigns an array the vertices of a basic cube.
	/// @param verts The array to assign to.
	/// @param size The size multiplier for the cube.
	/// 
	static void vertices(GLfloat verts[], float size);

	/// 
	/// Assigns an array the indices of a basic cube.
	/// @param inds The array to assign to.
	/// 
	static void indices(GLuint inds[]);
};

#endif // GENERATOR_H