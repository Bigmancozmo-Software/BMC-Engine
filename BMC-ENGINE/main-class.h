#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H

#include <iostream>
#include "rendering/window/Window.h"

class main {
public:
	static Window* window;
	inline static std::string locale = "en-US";
};

#endif