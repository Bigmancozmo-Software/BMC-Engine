#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "stb_image.h"

#include "Vector2.hpp"

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

private:
	void _create(const char* title, int width, int height);
	void _setSize(int width, int height);
};