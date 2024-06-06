#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "ErrorDefinitions.h"
#include <string>
#include <GLFW/glfw3.h>

#include "../lang/Translator.h"
#include "../../main-class.h"

#ifdef WIN32
#include <Windows.h>
#endif

class ErrorHandler {
public:
	static void ErrorPopup(int type, const char* _text);
};

#endif // ERROR_HANDLER_H