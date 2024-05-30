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

GLenum glCheckError_(const char* file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::string error;
		switch (errorCode)
		{
		case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__) 

int main(int argc, char* argv[])
{
	Window* window = new Window("BMC Engine", 800, 800);
	window->initImGui();

	// OpenGL!
	GLfloat vertices[] = {
		 // Coordinates    // Colors      // Textures
		 0.5f,  0.5f,  0.5f, 255, 155, 79,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 255, 155, 79, -1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 255, 155, 79, -1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 255, 155, 79,  1.0f, 0.0f,

		-0.5f,  0.5f, -0.5f, 255, 155, 79,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 255, 155, 79, -1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 255, 155, 79, -1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 255, 155, 79,  1.0f, 0.0f
	};
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3,

		4, 5, 7,
		5, 6, 7,

		1, 2, 4,
		2, 4, 7,

		1, 4, 5,
		0, 1, 5,

		0, 5, 6,
		0, 3, 6,

		2, 6, 7,
		2, 3, 6
	};

	GLfloat lightVertices[] = {
		 // Coordinates
		 0.1f,  0.1f,  0.1f,
		-0.1f,  0.1f,  0.1f,
		-0.1f, -0.1f,  0.1f,
		 0.1f, -0.1f,  0.1f,

		-0.1f,  0.1f, -0.1f,
		 0.1f,  0.1f, -0.1f,
		 0.1f, -0.1f, -0.1f,
		-0.1f, -0.1f, -0.1f
	};
	GLuint lightIndices[] = {
		0, 1, 3,
		1, 2, 3,

		4, 5, 7,
		5, 6, 7,

		1, 2, 4,
		2, 4, 7,

		1, 4, 5,
		0, 1, 5,

		0, 5, 6,
		0, 3, 6,

		2, 6, 7,
		2, 3, 6
	};

	Shader* defaultShader = new Shader("./resources/shaders/default/vertex.glsl", "./resources/shaders/default/fragment.glsl");
	Shader* lightShader = new Shader("./resources/shaders/light/vertex.glsl", "./resources/shaders/light/fragment.glsl");

	VAO vao;
	VBO vbo(vertices, sizeof(vertices) / sizeof(float));
	EBO ebo(indices, sizeof(indices) / sizeof(int));

	vao.bind();
	vbo.bind();
	ebo.bind();

	defaultShader->vertexAttribPointer(0, 3, GL_FLOAT, 8, 0);
	defaultShader->vertexAttribPointer(1, 3, GL_FLOAT, 8, 3);
	defaultShader->vertexAttribPointer(2, 2, GL_FLOAT, 8, 6);
	
	glm::vec3 cubePos = glm::vec3(0.0f);
	glm::mat4 cubeModel = glm::mat4(1.0f);
	cubeModel = glm::translate(cubeModel, cubePos);
	defaultShader->use();
	defaultShader->setMat4("model", cubeModel);
	
	glBindVertexArray(0);

	vao.unbind();
	vbo.unbind();
	ebo.unbind();

	VAO lightVAO;
	VBO lightVBO(lightVertices, sizeof(lightVertices) / sizeof(float));
	EBO lightEBO(lightIndices, sizeof(lightIndices) / sizeof(float));

	lightShader->use();

	lightVAO.bind();
	lightVBO.bind();
	lightEBO.bind();

	lightShader->vertexAttribPointer(0, 3, GL_FLOAT, 3, 0);

	// Bind VAO and VBO to 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	Styler::setToDefault();

	DebugUtil* debugger = new DebugUtil(window->getWindow());

	bool useDebugger = (checkArg(argc, argv, "--debugger")) || (checkArg(argc, argv, "-d"));

// If in debug mode, immediately set useDebugger to true.
#ifndef NDEBUG
	useDebugger = true;
#endif

	srand(time(nullptr));
	int randomNumber = rand() % 7 + 1;
	string fileDir = "resources/img/icon/logo_" + to_string(randomNumber) + ".png";
	window->setIcon(fileDir.c_str());

	Texture smiley("resources/img/smiley.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	smiley.texUnit(defaultShader, "tex0", 0);

	glEnable(GL_DEPTH_TEST);

	Camera camera(window->getSize(), glm::vec3(0.0f, 0.0f, 1.7f));

	window->maximize();

	// main loop
	while (!(window->shouldClose()))
	{
		glClearColor(0.6f, 0.5f, 0.8f, 1.0f); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();

		camera.inputs(window);
		camera.updateMatrix(DebugSettings::camFOV, 0.001f, 100.0f);

		defaultShader->use();
		defaultShader->setFloat("scale", DebugSettings::renderScale);

		camera.matrix(defaultShader, "camMatrix");

		smiley.bind();
		vao.bind();

		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		smiley.unbind();

		lightShader->use();
		lightShader->setFloat("scale", DebugSettings::renderScale);

		lightVAO.bind();

		camera.matrix(lightShader, "camMatrix");

		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		if(useDebugger)
			debugger->draw();

		camera.speed = DebugSettings::camSpeed;

		glfwSwapBuffers(window->getWindow());		
	}

	vao.cleanup();
	vbo.cleanup();
	ebo.cleanup();

	smiley.cleanup();

	delete defaultShader;
	delete window;
	delete debugger;

	return 0;
}
