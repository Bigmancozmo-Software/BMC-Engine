#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
//#include <glm/gtx/vector_angle.hpp>

#include "../shaders/Shader.h"
#include "../../window/Window.h"

class Camera {
public:
	glm::vec3 position;
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	bool firstClick = true;

	int width;
	int height;

	float speed = 0.012f;
	float sensitivity = 365.5f;

	Camera(int width, int height, glm::vec3 position);
	Camera(Vector2* size, glm::vec3 position);

	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
	void matrix(Shader* shader, const char* uniform);
	void inputs(Window* window);
};