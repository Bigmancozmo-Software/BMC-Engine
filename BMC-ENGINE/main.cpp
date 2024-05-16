#include "main.h"

#if WIN32
#include <Windows.h>
#endif

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool checkArg(int argc, char* argv[], std::string arg) {
	for (int i = 1; i < argc; ++i) {
		if (argv[i] == arg) {
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	// Create GLFW window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "GLFW Window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL" << std::endl;
		return -1;
	}

	glViewport(0, 0, 1280, 720);

	// callbacks
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// initialize imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	// OpenGL!

	Shader defaultShader("./resources/shaders/default/vertex.glsl", "./resources/shaders/default/fragment.glsl");

	Styler::setToDefault();

	DebugUtil debugger(window);

	bool useDebugger = checkArg(argc, argv, "--build");
	
#ifndef NDEBUG // If in debug mode, immediately set useDebugger to true.
	useDebugger = true;
#endif

	srand(time(nullptr));
	string fileName = to_string(rand() % 7 + 1);
	string fileDir = "resources/img/icon/logo_" + fileName + ".png";

	// App Icon
	stbi_set_flip_vertically_on_load(false);
	int icon_width, icon_height, icon_channels;
	unsigned char* icon_image = stbi_load(fileDir.c_str(), &icon_width, &icon_height, &icon_channels, 4);
	GLFWimage app_icon[1];
	app_icon[0].width = icon_width;
	app_icon[0].height = icon_height;
	app_icon[0].pixels = icon_image;
	glfwSetWindowIcon(window, 1, app_icon);

	// main loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		if(useDebugger)
			debugger.draw();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	stbi_image_free(icon_image);

	return 0;
}