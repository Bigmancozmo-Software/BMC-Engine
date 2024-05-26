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
	Window* window = new Window("BMC Engine", 800, 800);
	window->initImGui();

	// OpenGL!
	Shader* defaultShader = new Shader("./resources/shaders/default/vertex.glsl", "./resources/shaders/default/fragment.glsl");

	float vertices[] = {
		 // Coordinates    // Colors      // Textures
		 0.5f, 1.0f,  0.5f, 255, 155, 79,  1.0f, 1.0f,
		-0.5f, 1.0f,  0.5f, 255, 155, 79, -1.0f, 1.0f,
		-0.5f, 0.0f,  0.5f, 255, 155, 79, -1.0f, 0.0f,
		 0.5f, 0.0f,  0.5f, 255, 155, 79,  1.0f, 0.0f,

		-0.5f, 1.0f, -0.5f, 255, 155, 79,  1.0f, 1.0f,
		 0.5f, 1.0f, -0.5f, 255, 155, 79, -1.0f, 1.0f,
		 0.5f, 0.0f, -0.5f, 255, 155, 79, -1.0f, 0.0f,
		-0.5f, 0.0f, -0.5f, 255, 155, 79,  1.0f, 0.0f,
	};
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3,

		4, 5, 7,
		5, 6, 7,

		1, 2, 4,
		2, 4, 7,

		1, 4, 5,
		0, 1, 5,
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

	// Tell OpenGL to read vertex coordinates
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Tell OpenGL to read RGB color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	// Tell OpenGL to read texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// Bind VAO and VBO to 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	Styler::setToDefault();

	DebugUtil debugger(window->getWindow());

	bool useDebugger = (checkArg(argc, argv, "--debugger")) || (checkArg(argc, argv, "-d"));

// If in debug mode, immediately set useDebugger to true.
#ifndef NDEBUG
	useDebugger = true;
#endif

	srand(time(nullptr));
	string fileName = to_string(rand() % 7 + 1);
	string fileDir = "resources/img/icon/logo_" + fileName + ".png";
	window->setIcon(fileDir.c_str());

	// img
	Texture* smiley = new Texture("resources/img/smiley.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	smiley->texUnit(defaultShader, "tex0", 0);

	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	// main loop
	while (!(window->shouldClose()))
	{
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		defaultShader->use();

		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= (1.0f / 60.0f)) {
			rotation += 0.5;
			prevTime = crntTime;
		}

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::scale(model, glm::vec3(0.5, 0.5, 0.5));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)(window->getWidth() / window->getHeight()), 0.1f, 100.0f);
		defaultShader->setMat4("model", model);
		defaultShader->setMat4("view", view);
		defaultShader->setMat4("proj", proj);

		smiley->bind();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		if(useDebugger)
			debugger.draw();

		defaultShader->setFloat("scale", DebugSettings::renderScale);

		glfwSwapBuffers(window->getWindow());
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	delete defaultShader;
	delete window;
	delete smiley;

	return 0;
}
