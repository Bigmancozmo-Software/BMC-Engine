#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H

#include <iostream>
#include "classes/lang/Translator.h"

class main {
public:
	inline static std::string locale = "en-US";
	inline static Translator* translator = new Translator(locale);

	inline static std::string translate(std::string key) {
		return translator->translate(key);
	}
};

#endif