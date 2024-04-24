#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class DebugUtil {
public:
	DebugUtil(GLFWwindow*);
	void draw();
private:
	GLFWwindow* window;
	void processVars();
};

class DebugSettings {
public:
	inline static bool useAntiAliasing = true;
};