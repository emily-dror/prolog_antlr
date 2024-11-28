#pragma once

#include <filesystem>
#include <fstream>

#include "Utils.hpp"


namespace PrologCompiler {

/**
 * @class Compiler
 * @brief Main class of the prolog compiler
 *
 */
class Compiler {
public:
    Compiler() = default;
    ~Compiler() = default;

    /**
     * @brief Compiles the file to prolog, with additional semantics.
     *
     * @param pathToTheFile: path to the traget file to compile.
     */
    void compile(const std::filesystem::path& pathToTheFile);

private:
    std::ifstream m_target; // File to compile
};
} // namespace PrologCompiler
