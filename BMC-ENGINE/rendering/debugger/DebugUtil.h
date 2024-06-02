#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H

#include "../../classes/lang/Translator.h"
#include "../../main-class.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class DebugUtil {
public:
	DebugUtil(GLFWwindow*);
	~DebugUtil();
	void draw();
private:
	// buttons
	bool resetScale = false;

	// other
	GLFWwindow* window;
	void processVars();
	Translator* translator;
};

class DebugSettings {
public:
	inline static bool useAntiAliasing = true;
	inline static float renderScale = 1.0f;
	inline static float camSpeed = 0.012f;
	inline static float camSensitivity = 365.5f;
	inline static float camFOV = 120.0f;
};

#endif // DEBUG_UTIL_H