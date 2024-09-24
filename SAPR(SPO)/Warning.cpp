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

bool Warning::compileCode() {
    std::ofstream tempFile("temp_code.cpp");
    if (tempFile.is_open()) {
        tempFile << code; 
        tempFile.close();
    }
    else {
        std::cerr << "Error: create temporary file." << std::endl;
        return false;
    }

    std::string command = "g++ temp_code.cpp -o temp_output 2> errors.txt";
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "\t\t\t| Compilation failed! |" << std::endl << "\t\t\t -----------------------" << std::endl;
        std::ifstream errorFile("errors.txt");
        std::string errorLine;
        while (std::getline(errorFile, errorLine)) {
            std::cerr << errorLine << std::endl;
        }
        return false;
    }
    else {
        std::cout << "\t\t\t| Compilation succeeded! |" << std::endl <<"\t\t\t -----------------------"<<std::endl;
        return true;
    }
}

bool Warning::isError() {
    getCode();  
    return !compileCode();
}
