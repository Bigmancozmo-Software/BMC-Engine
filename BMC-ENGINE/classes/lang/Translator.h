#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>

#include "../../files/FileReader.h"
#include <unordered_map>

class Translator {
public:
	Translator(std::string locale);
	std::string translate(std::string key);
private:
	std::unordered_map<std::string, std::string> languageMap;
};

#endif