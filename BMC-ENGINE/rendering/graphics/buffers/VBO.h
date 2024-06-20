#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"

#include <iostream>

class VBO {
public:
	/// 
	/// The ID to store the VBO to.
	/// 
	GLuint id;

	/// 
	/// Create the VBO.
	/// @param verts The vertices array.
	/// @param length The amount of items in the vertices array.
	///
	VBO(GLfloat* verts, int length);

	/// 
	/// Bind the VBO buffer.
	/// 
	void bind();

	/// 
	/// Unbind the VBO buffer.
	/// 
	void unbind();

	/// 
	/// Delete the VBO buffer.
	/// 
	void cleanup();
private:
	GLfloat* vertices;
	int size;
};

#endif // VBO_H