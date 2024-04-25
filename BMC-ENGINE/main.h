#pragma once

#define STB_IMAGE_IMPLEMENTATION

// ImGui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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
#include "files/image/ImageLoader.h"