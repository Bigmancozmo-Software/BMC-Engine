#include "Window.h"

// PUBLIC METHODS

Window::Window(const char* title, int width, int height)
{
	_create(title, width, height);
}

Window::Window(const char* title, Vector2 size)
{
	_create(title, size.x, size.y);
}

Window::Window(const char* title)
{
	_create(title, 1270, 720);
}

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::setIcon(const char* file)
{
	stbi_set_flip_vertically_on_load(false);
	int icon_width, icon_height, icon_channels;
	unsigned char* icon_image = stbi_load(file, &icon_width, &icon_height, &icon_channels, 4);
	GLFWimage app_icon[1];
	app_icon[0].width = icon_width;
	app_icon[0].height = icon_height;
	app_icon[0].pixels = icon_image;
	glfwSetWindowIcon(window, 1, app_icon);
}

void Window::setSize(int width, int height)
{
	_setSize(width, height);
}

void Window::setSize(Vector2 size)
{
	_setSize(size.x, size.y);
}

void Window::initImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
}

GLFWwindow* Window::getWindow()
{
	return window;
}

// PRIVATE METHODS

void Window::_create(const char* title, int width, int height)
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		glfwTerminate();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL" << std::endl;
		glfwTerminate();
	}

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window, _framebuffer_size_callback);
}

void Window::_setSize(int width, int height)
{
	glfwSetWindowSize(window, width, height);
	glViewport(0, 0, width, height);
}

void Window::_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
