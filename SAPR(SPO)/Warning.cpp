#include "Warning.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void Warning::getCode() {
    std::ifstream inputFile("input.txt"); 
    if (!inputFile.is_open()) {
        std::cerr << "Error: open input file." << std::endl;
        return;
    }

    std::string line;
    line.clear(); 
    while (std::getline(inputFile, line)) {
        code += line + "\n";  
    }
    inputFile.close(); 
}

void Warning::compileCode() {
    std::ofstream tempFile("temp_code.cpp");
    if (tempFile.is_open()) {
        tempFile << code; 
        tempFile.close();
    }
    else {
        std::cerr << "Error: create temporary file." << std::endl;
        return;
    }

    std::string command = "g++ temp_code.cpp -o temp_output 2> errors.txt";
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Compilation failed!" << std::endl;
        std::ifstream errorFile("errors.txt");
        std::string errorLine;
        while (std::getline(errorFile, errorLine)) {
            std::cerr << errorLine << std::endl;
        }
    }
    else {
        std::cout << "Compilation succeeded!" << std::endl;
    }
}

bool Warning::isError() {
    getCode();  
    compileCode();  
    return false;  
}
