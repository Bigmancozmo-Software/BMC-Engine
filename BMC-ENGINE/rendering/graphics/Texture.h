#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "../shaders/Shader.h"
#include "stb_image.h"

class Texture
{
public:
	/// 
	/// The ID to store the texture to.
	/// 
	GLuint ID;

	/// 
	/// The type of texture to store.
	/// 
	GLenum type;

	/// 
	/// The OpenGL texture slot to store the texture to.
	/// 
	GLuint unit;

	/// 
	/// Creates the texture object.
	/// @param image The path to the image file.
	/// @param texType The type of texture to store
	/// @param slot The OpenGL texture slot to store the texture to.
	/// @param format The texture's color format (ex. RGBA)
	/// @param pixelType The texture's pixel type (ex. GL_UNSIGNED_BYTE)
	/// 
	Texture(const char* image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType);

	/// 
	/// Assigns the texture to the shader.
	/// @param shader The Shader object to assign the texture to.
	/// @param uniform The name of the uniform in the fragment shader for the texture.
	/// @param unit The texture's slot, as an integer.
	/// 
	void texUnit(Shader* shader, const char* uniform, GLuint unit);

	/// 
	/// Bind the texture.
	/// 
	void bind();

	/// 
	/// Unbind the texture.
	/// 
	void unbind();

	/// 
	/// Delete the texture.
	///
	void cleanup();
};

#endif // TEXTURE_H