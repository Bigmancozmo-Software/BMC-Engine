#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "../../files/FileReader.h"

/// 
/// Makes OpenGL shader creation easier by providing simple functions.
/// 
class Shader
{
public:
    /// 
    /// The ID to assign the shader to.
    /// 
    GLuint ID;

    /// 
    /// The ID to assign the shader to.
    /// 
    Shader(const char* vertexPath, const char* fragmentPath);

    /// 
    /// The ID to assign the shader to.
    /// 
    void use();

    /// 
    /// Sets a boolean uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setBool(const std::string& name, bool value) const;

    /// 
    /// Sets an integer uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setInt(const std::string& name, int value) const;

    /// 
    /// Sets a float uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setFloat(const std::string& name, float value) const;

    /// 
    /// Sets a mat4 uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setMat4(const std::string& name, glm::mat4 value) const;

    /// 
    /// Sets a vec3 uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setVec3(const std::string& name, glm::vec3 value) const;

    /// 
    /// Sets a vec4 uniform in the shader.
    /// @param name The name of the uniform.
    /// @param value The value to set it to.
    /// 
    void setVec4(const std::string& name, glm::vec4 value) const;

    /// 
    /// Create a vertex attribute pointer.
    /// @param index The index in the vertices array.
    /// @param length The length of the vertex attribute pointer (ex. a vec3 would be 3).
    /// @param type The type of the data in the vertices array.
    /// @param totalSize The length of 1 vertex in the vertices array.
    /// 
    void vertexAttribPointer(int index, int length, int type, int totalSize);

private:
    int sizeofMultiplier = 0;
};

#endif // SHADER_H