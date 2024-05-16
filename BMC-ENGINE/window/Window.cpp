#include "Window.h"

// PUBLIC METHODS

Window::Window(const char* title, int width, int height)
{
}

Window::Window(const char* title, Vector2 size)
{
}

Window::Window(const char* title)
{
}

Window::~Window()
{
}

bool Window::shouldClose()
{
	return false;
}

void Window::setIcon(const char* file)
{
}

void Window::setSize(int width, int height)
{
}

void Window::setSize(Vector2 size)
{
}

// PRIVATE METHODS

void Window::_create(const char* title, int width, int height)
{
}

void Window::_setSize(int width, int height)
{
}
