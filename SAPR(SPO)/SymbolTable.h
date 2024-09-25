#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <iostream>
#include <vector>

class SymbolTable
{
	std::vector <std::string> operators;
	std::vector <std::string> keyWords;
	bool isIncrement(const std::string& token);
public:
	SymbolTable();

	bool isOperator(const std::string& token);
	bool isKeyWord(const std::string& token);

	bool isDigit(const std::string& token);
	bool isIdentifier(const std::string& token);
};

#endif SYMBOL_TABLE_H

