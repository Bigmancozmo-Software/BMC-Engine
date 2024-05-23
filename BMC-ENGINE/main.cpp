#include "main.h"

using namespace std;

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
	Window* window = new Window("BMC Engine");
	window->initImGui();

	// OpenGL!
	Shader defaultShader("./resources/shaders/default/vertex.glsl", "./resources/shaders/default/fragment.glsl");

	Styler::setToDefault();

	DebugUtil debugger(window->getWindow());

	bool useDebugger = checkArg(argc, argv, "--build");
	
#ifndef NDEBUG // If in debug mode, immediately set useDebugger to true.
	useDebugger = true;
#endif

	srand(time(nullptr));
	string fileName = to_string(rand() % 7 + 1);
	string fileDir = "resources/img/icon/logo_" + fileName + ".png";

	// App Icon
	

	// main loop
	while (!(window->shouldClose()))
	{
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		if(useDebugger)
			debugger.draw();

		glfwSwapBuffers(window->getWindow());
	}

	delete window;

	return 0;
}