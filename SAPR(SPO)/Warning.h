#ifndef WARNING_H
#define WARNING_H
#include <string>

class Warning {

    std::string code;
    void getCode();
    void compileCode();
public:
    bool isError();
};

#endif // WARNING_H
