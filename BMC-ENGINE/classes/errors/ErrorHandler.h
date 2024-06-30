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

/// 
/// Handles errors in the program.
/// 
class ErrorHandler {
public:
	/// 
	/// Creates and OS-specific popup if an error occurred.
	/// @param type The severity, from ErrorDefinitions.h, that the error is.
	/// @param _text The message in the popup.
	/// 
	static void ErrorPopup(int type, const char* _text);
};

#endif // ERROR_HANDLER_H