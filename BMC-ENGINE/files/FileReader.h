#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FileReader {
public:
	static std::string readFile(const char* path);
};

#endif