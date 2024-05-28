#ifndef VAO_H
#define VAO_H

#include "glad/glad.h"

class VAO {
public:
	GLuint id;
	VAO();

	void bind();
	void cleanup();
};

#endif // VAO_H