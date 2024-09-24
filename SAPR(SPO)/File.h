#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <string>

class File
{
	std::ifstream inFile;
	std::string line;
	std::string nameFile {"input.txt"};
	void checkOpen();

public:
	void formatInString();
	std::string getLine();
};


#endif // !FILE_H
