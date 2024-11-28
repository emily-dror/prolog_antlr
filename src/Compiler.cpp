#include "Compiler.hpp"
#include "Visitors.hpp"
#include "prologLexer.h"
#include "prologParser.h"
#include <filesystem>
#include <fstream>

namespace Prolog {

// NOTE: There is no need for this function, replaces by ProgramRestoreVisitor.
// std::list<antlr4::tree::ParseTree*> Compiler::getProgramList(antlr4::tree::ParseTree* root) const {
//     if (root == nullptr) {
//         return {};
//     }
//
//     if (root->children.empty()) {
//         return {root};
//     }
//
//     auto leaves = std::list<decltype(root)>{};
//
//     for (auto* child : root->children) {
//         auto childList = getProgramList(child);
//         leaves.splice(leaves.end(), childList);
//     }
//
//     return leaves;
// }

// TODO: Organize this miss.
void Compiler::compile(const std::filesystem::path& path, const std::set<Flag>& flags) {
    std::ifstream targetFile{path};

    if (!targetFile) {
        std::cerr << "Error opening the file: " << path << '\n';
    }

    auto enabled = [&flags](Flag flag) { return flags.find(flag) != flags.end(); };

    // Create ANTLR input stream
    antlr4::ANTLRInputStream input(targetFile);
    // Create Lexer and TokenStream
    prologLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);

    prologParser parser(&tokens);

    auto* programStartCtx = parser.p_text();

    Visitors::VariableSemanticVisitor varV;

    varV.visit(programStartCtx);

    if (enabled(Flag::VAR_NUM_CHECK)) {
        if (varV.invalidVars != 0) {
            std::cerr << "Variables must occur at least twice" << '\n';
            exit(-1);
        }
    }

    if (enabled(Flag::COMP_TO_PROLOG)) {
        Visitors::ProgramRestoreVisitor progRestoreV;

        progRestoreV.visit(programStartCtx);
        auto progList = progRestoreV.programList;
    }

    if (enabled(Flag::GEN_AST)) {
        Visitors::ProgramRestoreVisitor progRestoreV;

        progRestoreV.visit(programStartCtx);
        auto progList = progRestoreV.programList;
    }
}



} // namespace Prolog
