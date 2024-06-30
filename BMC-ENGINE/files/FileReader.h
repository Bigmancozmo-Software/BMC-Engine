#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FileReader {
public:
	/// 
	/// Reads the contents of a file.
	/// @param path The location of the file.
	/// @return The contents of the file, as an std::string.
	/// 
	static std::string readFile(const char* path);
};

#endif