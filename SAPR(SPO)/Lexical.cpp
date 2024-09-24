#include "Lexical.h"
#include <sstream>
#include <iostream>

void  Lexical::tokenization(const std::string& input)
{
	
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
		tokens.push_back(token);
}

void Lexical::classifyTokens()
{
	for (const std::string& token : tokens)
	{
		if (symbolTable.isKeyWord(token))
			if (token.back() == ';')
			{
				std::string tempToken = token;
				tempToken.pop_back();
				std::cout << tempToken << " :keyword" << std::endl;
			}
			else
				std::cout << token << " :keyword" << std::endl;

		else if (symbolTable.isOperator(token))
		{
			std::cout << token << " :operator" << std::endl;
		}
		else if (symbolTable.isDigit(token))
		{
			if (token.back() == ';')
			{
				std::string tempToken = token;
				tempToken.pop_back();
				if(!tempToken.empty())
					std::cout << tempToken << " :number" << std::endl;
			}
			else
				std::cout << token << " :number" << std::endl;
		}
		else
		{
			
			if (token == ")" || token == "(" || token =="}" || token=="{")
				continue;
			std::cout << token << " :identifier" << std::endl;
		}
	}
}


