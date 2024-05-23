#pragma once

#include "ErrorDefinitions.h"
#include <string>
#include <GLFW/glfw3.h>

#ifdef WIN32
#include <Windows.h>
#endif

class ErrorHandler {
public:
	static void ErrorPopup(int type, const char* _text);
};