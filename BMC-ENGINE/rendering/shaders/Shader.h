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

class Shader
{
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setMat4(const std::string& name, glm::mat4 value) const;
    void setVec3(const std::string& name, glm::vec3 value) const;
    void setVec4(const std::string& name, glm::vec4 value) const;

    void vertexAttribPointer(int index, int length, int type, int totalSize);

private:
    int sizeofMultiplier = 0;
};

#endif // SHADER_H