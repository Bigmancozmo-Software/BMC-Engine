#ifndef MAIN_H
#define MAIN_H

// Builtin C++
#include <iostream>
#include <cstring>
#include <sstream>

// Rendering
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// My classes
#include "rendering/debugger/Styling.h"
#include "rendering/debugger/DebugUtil.h"

#include "rendering/graphics/Texture.h"
#include "rendering/graphics/Camera.h"
#include "rendering/graphics/buffers/VAO.h"
#include "rendering/graphics/buffers/VBO.h"
#include "rendering/graphics/buffers/EBO.h"

#include "rendering/shaders/Shader.h"

#include "rendering/model/Generators.h"

#include "rendering/window/Window.h"

#include "files/FileReader.h"

#include "classes/lang/Translator.h"

#include "main-class.h"


// stb
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#endif // MAIN_H