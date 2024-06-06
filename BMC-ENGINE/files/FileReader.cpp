#include "FileReader.h"

std::string FileReader::readFile(const char* path)
{
    std::string fileContents;
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open(path);

        std::stringstream fileStream;
        fileStream << file.rdbuf();

        file.close();

        fileContents = fileStream.str();

        return fileContents;
    }
    catch (std::ifstream::failure e) {
        std::cout << "Failed to read file'" << path << "'" << std::endl;
    }

    return std::string();
}
