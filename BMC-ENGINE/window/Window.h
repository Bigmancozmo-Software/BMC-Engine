#pragma once

//#define STB_IMAGE_IMPLEMENTATION

//#include "stb_image.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Vector2.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#ifdef WIN32
#include <windows.h>
#endif

class Window {
public:
	Window(const char* title, int width, int height); // title with size
	Window(const char* title, Vector2 size); // ditto
	Window(const char* title); // title with default size (1270x720)
	~Window();
	
	bool shouldClose();
	
	void setIcon(const char* file);

	void setSize(int width, int height);
	void setSize(Vector2 size);
	void initImGui();

	GLFWwindow* getWindow();

private:
	void _create(const char* title, int width, int height);
	void _setSize(int width, int height);
	static void _framebuffer_size_callback(GLFWwindow* window, int width, int height);
	
	GLFWwindow* window;
};
