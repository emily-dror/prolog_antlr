#pragma once

#include <fstream>

namespace PrologCompiler {


struct Symbol{
    std::string name;
    std::string type;
};

class Compiler{
public:
    Compiler() = default;
    ~Compiler() = default;

    void compile(const std::ifstream&);
private:
    std::ifstream m_file;
};
}
