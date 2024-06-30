#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H

#include "../../classes/lang/Translator.h"
#include "../../main-class.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

/// 
/// The utility used for debugging & experimentation.
/// 
/// Enabled with the --debug (-d) launch argument or when the engine is a debug build.
/// 
class DebugUtil {
public:
	/// 
	/// Creates the utility
	/// @param window The GLFWwindow* used for ImGui.
	/// 
	DebugUtil(GLFWwindow* window);

	/// 
	/// Shutdown & destroy ImGui.
	/// 
	~DebugUtil();

	/// 
	/// Draw the debugger on the screen.
	/// 
	void draw();

private:
	// buttons
	bool resetScale = false;

	// other
	GLFWwindow* window;
	void processVars();
};

class DebugSettings {
public:
	/// 
	/// Should the renderer use antialiasing?
	/// 
	inline static bool useAntiAliasing = true;

	/// 
	/// All vertex coordinates will be multiplied by this value.
	/// 
	inline static float renderScale = 1.0f;

	/// 
	/// The speed of camera movement.
	/// 
	inline static float camSpeed = 0.012f;

	/// 
	/// Camera rotation sensitivity.
	/// 
	inline static float camSensitivity = 365.5f;

	/// 
	/// The field of view for the camera.
	/// 
	inline static float camFOV = 120.0f;
};

#endif // DEBUG_UTIL_H