#ifndef WINDOW_H
#define WINDOW_H

#include "stb_image.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "math/Vector.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "errors/ErrorHandler.h"

class Window {
public:
	/// 
	/// Creates the window object.
	/// @param title const char* to assign to the window's name to.
	/// @param width The width, in pixels, to create the window with.
	/// @param width The height, in pixels, to create the window with.
	/// 
	Window(const char* title, int width, int height); // title with size

	/// 
	/// Creates the window object.
	/// @param title const char* to assign to the window's name to.
	/// @param size The size, as a Vector2, to set the window size to.
	/// 
	Window(const char* title, Vector2 size); // ditto

	/// 
	/// Creates the window object.
	/// @param title const char* to assign to the window's name to.
	/// 
	Window(const char* title);

	/// 
	/// Delete the window and clean up GLFW.
	/// 
	~Window();
	
	/// 
	/// @return Is the window still open?
	/// 
	bool shouldClose();
	
	/// 
	/// Sets the icon of the window on the taskbar and title bar.
	/// @param file The file path to set the icon to.
	/// 
	void setIcon(const char* file);

	/// 
	/// Set the size of the window.
	/// @param width The width, in pixels, to set.
	/// @param height The height, in pixels, to set.
	/// 
	void setSize(int width, int height);

	/// 
	/// Set the size of the window.
	/// @param size The size, as a Vector2, to set.
	/// 
	void setSize(Vector2 size);

	/// 
	/// Initialize ImGui
	/// 
	void initImGui();

	/// 
	/// Call glfwSetWindowShouldClose to tell GLFW to close the window.
	/// 
	void close();

	/// 
	/// Maximize the window.
	/// 
	void maximize();

	/// 
	/// @return The width of the window, in pixels.
	/// 
	int getWidth();

	/// 
	/// @return The height of the window, in pixels.
	/// 
	int getHeight();

	/// 
	/// @return A pointer to the window's size, as a Vector2.
	/// 
	Vector2* getSize();

	/// 
	/// @return A pointer to the GLFWwindow associated with this Window class.
	/// 
	GLFWwindow* getWindow();

private:
	bool _create(const char* title, int width, int height);
	void _setSize(int width, int height);
	void _calcViewport(int width, int height);
	static void _framebuffer_size_callback(GLFWwindow* window, int width, int height);
	
	GLFWwindow* window;
};

#endif // WINDOW_H