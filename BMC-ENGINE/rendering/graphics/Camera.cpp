#include "Camera.h"

Camera::Camera(int winWidth, int winHeight, glm::vec3 position)
{
	this->position = position;
	this->winHeight = winHeight;
	this->winWidth = winWidth;
}

Camera::Camera(Vector2* size, glm::vec3 position)
{
	this->position = position;
	this->winHeight = size->y;
	this->winWidth = size->x;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	view = glm::lookAt(position, position + orientation, up);
	proj = glm::perspective(glm::radians(FOVdeg), (float)(winWidth / winHeight), nearPlane, farPlane);

	cameraMatrix = proj * view;
}

void Camera::matrix(Shader* shader, const char* uniform)
{
	shader->setMat4(uniform, cameraMatrix);
}

void Camera::inputs(Window* window)
{
	GLFWwindow* win = window->getWindow();

	if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
		position += speed * orientation;
	if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
		position += speed * -orientation;
	if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
		position += speed * -glm::normalize(glm::cross(orientation, up));
	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
		position += speed * glm::normalize(glm::cross(orientation, up));
	if (glfwGetKey(win, GLFW_KEY_Q) == GLFW_PRESS)
		position += speed * -up;
	if (glfwGetKey(win, GLFW_KEY_E) == GLFW_PRESS)
		position += speed * up;

	if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick) {
			glfwSetCursorPos(win, winWidth / 2, winHeight / 2);
			firstClick = false;
		}

		double mx, my;
		glfwGetCursorPos(win, &mx, &my);
		float rotX = sensitivity * (float)(my - (winHeight / 2)) / winHeight;
		float rotY = sensitivity * (float)(mx - (winHeight / 2)) / winHeight;

		glm::vec3 newOri = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));
		orientation = newOri;

		orientation = glm::rotate(orientation, glm::radians(-rotY), up);
		glfwSetCursorPos(win, winWidth / 2, winHeight / 2);
	}
	else if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE) {
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}

}
