#include "Translator.h"

Translator::Translator(std::string locale)
{
    std::string path = "resources/lang/" + locale + ".lang";
    std::string fileContent = FileReader::readFile(path.c_str());
    std::istringstream fileStream(fileContent);
    std::string line;

    while (std::getline(fileStream, line)) {
        // Find the position of the equals sign
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            languageMap[key] = value;
        }
    }
}

std::string Translator::translate(std::string key)
{
    if (languageMap.find(key) != languageMap.end()) {
        return languageMap[key];
    }
    return key;
}
