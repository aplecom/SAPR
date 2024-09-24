#include <iostream>
#include "Lexical.h"
#include "File.h"
#include "Warning.h"

int main() {
    using namespace std;
    File file;
    file.formatInString();

    Warning warning;
    if (warning.isError()) {
        getchar();
    }
    else {
        Lexical lexer;
        lexer.tokenization(file.getLine());
        lexer.classifyTokens();
    }

    return 0;
}
