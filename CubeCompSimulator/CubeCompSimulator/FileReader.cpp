#ifndef FILEREADER_HEADER
#define FILEREADER_HEADER
#include <math.h>
#include <string>
#include <fstream>

class FileReader {
public:
	std::ifstream file;
	FileReader(const std::string path) {
		file.open(path);
	}
	~FileReader() {
		if (file.is_open()) {
			file.close();
		}
	}
	std::string readLine() {
		if (FileReader::file.is_open()) {
			std::string line;
			std::getline(file, line);
			return line;
		}
		return "";
	}
};
#endif