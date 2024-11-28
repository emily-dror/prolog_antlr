#include "Compiler.hpp"
#include "Visitors.hpp"
#include "prologLexer.h"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <filesystem>
#include <fstream>
#include <variant>

namespace Prolog {

void Compiler::genProlog(prologParser& parser) {
    auto* programStartCtx = parser.p_text();
    Visitors::ProgramRestoreVisitor progRestoreV;



    progRestoreV.visit(programStartCtx);
    auto progList = progRestoreV.programList;

    auto outputPath = m_targetPath.replace_extension("").concat("_out.pl");

    std::ofstream outputFile(outputPath);

    if (!outputFile) {
        std::cerr << "Error opening the file: " << outputPath << '\n';
    }

    for (auto& stmtList : progList) {
        for (auto& stmt : stmtList) {
            std::visit([&outputFile](auto* arg) {outputFile << arg->getText() << " "; }, stmt);
        }
        outputFile<<'\n';
    }
}

void Compiler::genAst(prologParser& parser) {
    auto* programStartCtx = parser.p_text();

    auto outputPath = m_targetPath.replace_extension("").concat("_ast.out");

    std::ofstream outputFile(outputPath);

    if (!outputFile) {
        std::cerr << "Error opening the file: " << outputPath << '\n';
    }

    outputFile << programStartCtx->toStringTree();
}

void Compiler::compile(const std::filesystem::path& path, const std::set<Flag>& flags) {
    m_targetPath = path;

    std::ifstream targetFile{path};

    if (!targetFile) {
        std::cerr << "Error opening the file: " << path << '\n';
    }

    auto enabled = [&flags](Flag flag) { return flags.find(flag) != flags.end(); };

    antlr4::ANTLRInputStream input(targetFile);
    prologLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    prologParser parser(&tokens);


    genProlog(parser);
    genAst(parser);
}

} // namespace Prolog
