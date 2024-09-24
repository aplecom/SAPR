#include "File.h"

 void File::formatInString()
{
	checkOpen();
	std::string tempLine;
	line.clear();
	while (std::getline(inFile, tempLine))
		line += tempLine + " "; 
	inFile.close();
}

 std::string File::getLine()
 {
	 return line;
 }

void File::checkOpen()
 {
	inFile.open(nameFile);

	 if (!inFile.is_open())
	 {
		 std::cerr << "Error: The file could not be opened." << std::endl;
	 }
 }
