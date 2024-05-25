#pragma once

// Builtin C++
#include <iostream>
#include <cstring>

// Rendering
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// My classes
#include "Styling.h"
#include "rendering/shaders/Shader.h"
#include "rendering/debugger/DebugUtil.h"
#include "window/Window.h"

// stb
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// class
class main {
public:
	static Window* window;
};