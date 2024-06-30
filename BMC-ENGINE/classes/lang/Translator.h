#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>

#include "../../files/FileReader.h"
#include <unordered_map>

/// 
/// Reads & translates keys for the current locale.
/// 
class Translator {
public:
	/// 
	/// Create the translator object
	/// @param locale The language, ex en-US.
	/// 
	Translator(std::string locale);

	/// 
	/// Translate a key to the selected locale.
	/// @param key The key to translate.
	/// @return An std::string of the translated key.
	/// 
	std::string translate(std::string key);
private:
	std::unordered_map<std::string, std::string> languageMap;
};

#endif