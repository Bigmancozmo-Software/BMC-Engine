#include "main.h"

using namespace std;

static Window* window = new Window("BMC Engine");

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
	window->initImGui();

	// OpenGL!
	Shader* defaultShader = new Shader("./resources/shaders/default/vertex.glsl", "./resources/shaders/default/fragment.glsl");

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Connect EBO and indices array
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Tell OpenGL how to read coordinates
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind VAO and VBO to 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	Styler::setToDefault();

	DebugUtil debugger(window->getWindow());

	bool useDebugger = checkArg(argc, argv, "--build");

// If in debug mode, immediately set useDebugger to true.
#ifndef NDEBUG
	useDebugger = true;
#endif

	srand(time(nullptr));
	string fileName = to_string(rand() % 7 + 1);
	string fileDir = "resources/img/icon/logo_" + fileName + ".png";
	window->setIcon(fileDir.c_str());

	// main loop
	while (!(window->shouldClose()))
	{
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();

		defaultShader->use();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		if(useDebugger)
			debugger.draw();


		glfwSwapBuffers(window->getWindow());
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	delete defaultShader;
	delete window;

	return 0;
}
