#ifndef EBO_H
#define EBO_H

#include "glad/glad.h"

#include <iostream>

/// 
/// Element buffer object
/// 
class EBO {
public:
	/// 
	/// The ID to store the EBO to.
	/// 
	GLuint id;

	/// 
	/// Create the EBO.
	/// @param inds The indices array.
	/// @param length The amount of items in the indices array.
	///
	EBO(GLuint* inds, int length);

	/// 
	/// Bind the EBO buffer.
	/// 
	void bind();

	/// 
	/// Unbind the EBO buffer.
	/// 
	void unbind();

	/// 
	/// Delete the EBO buffer.
	/// 
	void cleanup();
private:
	GLuint* indices;
	int size;
};

#endif // EBO_H