#ifndef VAO_H
#define VAO_H

#include "glad/glad.h"

class VAO {
public:
	/// 
	/// The ID to store the VAO to.
	/// 
	GLuint id;

	/// 
	/// Create the VAO.
	///
	VAO();

	/// 
	/// Bind the VAO buffer.
	/// 
	void bind();

	/// 
	/// Unbind the VAO buffer.
	/// 
	void unbind();

	/// 
	/// Delete the VAO buffer.
	/// 
	void cleanup();
};

#endif // VAO_H