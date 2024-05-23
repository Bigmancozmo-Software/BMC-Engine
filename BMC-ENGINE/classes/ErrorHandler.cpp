#include "ErrorHandler.h"

void ErrorHandler::ErrorPopup(int type, const char* _text)
{
	bool windows = false;

#if defined(WIN32)
	windows = true;
#endif

	string textStr(_text);
	string text = "   " + textStr;

	switch (type) {
	case ERROR_CRITICAL:
		if (windows) { MessageBox(NULL, text.c_str(), "Critical Error", MB_ICONERROR | MB_OK); };
		main::window->close();
		break;
	case ERROR_CAN_CONTINUE:
		if (windows) { MessageBox(NULL, text.c_str(), "An Error Occurred", MB_ICONWARNING | MB_OK); };
		break;
	}
}
