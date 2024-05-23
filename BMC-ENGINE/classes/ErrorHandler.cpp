#include "ErrorHandler.h"

void ErrorHandler::ErrorPopup(int type, const char* _text)
{
	bool windows = false;

#if defined(WIN32)
	windows = true;
#endif

	std::string textStr(_text);
	std::string text = "   " + textStr;

	switch (type) {
	case ERROR_CRITICAL:
		if (windows) { MessageBox(NULL, text.c_str(), "Critical Error", MB_ICONERROR | MB_OK); };
		glfwTerminate(); // terminate the program
		break;
	case ERROR_CAN_CONTINUE:
		if (windows) { MessageBox(NULL, text.c_str(), "An Error Occurred", MB_ICONWARNING | MB_OK); };
		break;
	}
}
