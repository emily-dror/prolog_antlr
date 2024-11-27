#pragma once

#include <filesystem>
#include <fstream>



namespace PrologCompiler {
class Compiler {
public:
    Compiler() = default;
    ~Compiler() = default;
    void compile(const std::filesystem::path& pathToTheFile);

private:
    std::ifstream m_target; // File to compile
};
} // namespace PrologCompiler
