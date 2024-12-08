#pragma once

#include <filesystem>
#include <fstream>
#include <list>
#include <variant>

#include "Utils.hpp"

#include "prologParser.h"
namespace Prolog {

/**
 * @class Compiler
 * @brief Main class of the prolog compiler
 *
 */
class Compiler {
public:
    enum class Flag {
        VAR_NUM_CHECK = 0,
        COMP_TO_PROLOG,
        GEN_AST,
    };

    Compiler() = default;
    ~Compiler() = default;

    /**
     * @brief Compiles the file to prolog, with additional semantics.
     *
     * @param pathToTheFile: path to the traget file to compile.
     * @param flags
     */
    void compile(const std::filesystem::path& pathToTheFile, const std::set<Flag>& flags);

    static std::unique_ptr<prologParser> parse(const std::variant<std::filesystem::path, std::string>&);

private:
    std::filesystem::path m_targetPath;

    void varNumCheck(prologParser& parser);
    void genAst(prologParser& parser);
    void genProlog(prologParser& parser);

    bool enabled(Flag) const;
};
} // namespace Prolog
