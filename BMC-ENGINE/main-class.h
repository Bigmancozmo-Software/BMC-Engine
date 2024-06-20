#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H

#include <iostream>
#include "classes/lang/Translator.h"

class main {
public:
	/// 
	/// The program's locale for the translator.
	/// 
	inline static std::string locale = "en-US";

	/// 
	/// The program's translator.
	/// 
	inline static Translator* translator = new Translator(locale);

	/// 
	/// Global translate function, for the program's translator.
	/// @param key The key to translate.
	/// 
	inline static std::string translate(std::string key) {
		return translator->translate(key);
	}
};

#endif