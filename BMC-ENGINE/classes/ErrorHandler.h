#pragma once

#include "ErrorDefinitions.h"
#include "../main.h"
#include <string>
using namespace std;

#ifdef WIN32
#include <Windows.h>
#endif

class ErrorHandler {
public:
	static void ErrorPopup(int type, const char* _text);
};