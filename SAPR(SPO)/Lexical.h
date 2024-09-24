#ifndef LEXICAL_H
#define LEXICAL_H
#include<string>
#include<vector>
#include "SymbolTable.h"

class Lexical
{
	std::vector<std::string> tokens;
	SymbolTable symbolTable;
public:
	void tokenization(const std::string& input);
	void classifyTokens();

};


#endif // !LEXICAL_H

