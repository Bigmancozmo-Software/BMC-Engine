#include "ErrorHandler.h"

void ErrorHandler::ErrorPopup(int type, const char* _text)
{
	std::string textStr(_text);
	std::string text = "   " + textStr + "\n   The program will be aborted.";

#ifdef WIN32
	switch (type) {
	case ERROR_CRITICAL:
		MessageBox(NULL, text.c_str(), main::translate("window.error.critical.title").c_str(), MB_ICONERROR | MB_OK);
		glfwTerminate(); // terminate the program
		break;
	case ERROR_CAN_CONTINUE:
		MessageBox(NULL, text.c_str(), main::translate("window.error.regular.title").c_str(), MB_ICONWARNING | MB_OK);
		break;
	}
#endif
}
