#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
//#include <glm/gtx/vector_angle.hpp>

#include "../shaders/Shader.h"
#include "../../rendering/window/Window.h"

class Camera {
public:
	/// 
	/// The camera's position.
	/// 
	glm::vec3 position;

	/// 
	/// The camera's rotation.
	/// 
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);

	/// 
	/// The up vector.
	/// 
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	/// 
	/// The camera's matrix, which all vertices are multiplied by.
	/// 
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	/// 
	/// To be removed - ignore this.
	/// 
	bool firstClick = true;

	/// 
	/// The window's width.
	/// 
	int winWidth;

	/// 
	/// The window's height.
	/// 
	int winHeight;

	/// 
	/// The camera's movement speed.
	/// 
	float speed = 0.012f;

	/// 
	/// The camera's rotation sensitivity.
	/// 
	float sensitivity = 365.5f;

	/// 
	/// Creates the camera.
	/// @param winWidth The window's width.
	/// @param winHeight The window's height.
	/// @param position The camera's position.
	/// 
	Camera(int winWidth, int winHeight, glm::vec3 position);

	/// 
	/// Creates the camera.
	/// @param size The window's size, as a Vector3.
	/// @param position The camera's position.
	/// 
	Camera(Vector2* size, glm::vec3 position);

	/// 
	/// Project the matrix.
	/// @param FOVdeg The FOV, in degrees.
	/// @param nearPlane How close to the camera objects can be before getting clipped.
	/// @param farPlane How far away from the camera objects can be before getting clipped.
	/// 
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

	/// 
	/// Send the camera matrix to the shader.
	/// @param shader The vertex shader.
	/// @param uniform The name of the matrix uniform.
	/// 
	void matrix(Shader* shader, const char* uniform);

	/// 
	/// Process the camera's inputs.
	/// @param window The engine window.
	/// 
	void inputs(Window* window);
};

#endif // CAMERA_H