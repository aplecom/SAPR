#include "SymbolTable.h"
#include <algorithm>
#include <cctype>

SymbolTable::SymbolTable()
{
    operators = { "+", "-", "*", "/", "=", "%", 
        "++", "--", "==", "!=", ">", "<", ">=", 
        "<=", "!", "&&", "||",">>","<<"};

    keyWords = { "int", "return", "if", "else",
        "while", "for", "void", "char", "float", 
        "double", "break", "continue", "#include",
    "<iostream>", "namespace", "std", "using",
    "cout","cin","endl","main()"};
};

bool SymbolTable::isIncrement(const std::string& token)
{
    return (token.length() == 3 && token[0] == '+' && token[1] == '+' && isalpha(token[2]))
        || (token.length() == 3 && isalpha(token[0]) && token[1] == '+' && token[2] == '+');
}

bool SymbolTable::isOperator(const std::string& token)
{
    if(!isIncrement(token))
        return std::find(operators.begin(), operators.end(), token) != operators.end();
    return true;
}

bool SymbolTable::isKeyWord(const std::string& token)
{
    if (token.back() == ';')
    {
        std::string tempToken = token;
        tempToken.pop_back();
        return std::find(keyWords.begin(), keyWords.end(), tempToken) != keyWords.end();
    }
    else
        return std::find(keyWords.begin(), keyWords.end(), token) != keyWords.end();
}

bool SymbolTable::isDigit(const std::string& token)
{
    if (token.back() == ';')
    {
        auto iter = token.end() - 1;
        return !token.empty() && std::all_of(token.begin(), iter, isdigit);
    }
    else 
        return !token.empty() && std::all_of(token.begin(), token.end(), isdigit);

}

bool SymbolTable::isIdentifier(const std::string& token)
{
    if (token.empty() || !isalpha(token[0]) && token[0] != '_')
        return false;
    return std::all_of(token.begin(), token.end(), isalnum);
}
