#include "Compiler.hpp"
#include "ListTokenSource.h"
#include "SemanticChecker.hpp"
#include "prologLexer.h"
#include "prologParser.h"
#include "tree/ParseTree.h"
#include <filesystem>
#include <fstream>

namespace PrologCompiler {

void Compiler::compile(const std::filesystem::path& path) {
    std::ifstream targetFile{path};

    if (!targetFile) {
        std::cerr << "Error opening the file: " << path << '\n';
    }

    // Create ANTLR input stream
    antlr4::ANTLRInputStream input(targetFile);

    // Create Lexer and TokenStream
    prologLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);

    prologParser parser(&tokens);
    auto* semanticListener = new SemanticCheckListener(
        {SemanticCheckListener::Listeners::VAR_L, SemanticCheckListener::Listeners::PROG_PARSE_L});

    antlr4::tree::ParseTreeWalker::DEFAULT.walk(semanticListener, parser.p_text());

    DEBUG(for (auto [name, var] : semanticListener->varSemanticChecker->varTbl) {
        std::cout << "Variable " << name << ", Count: " << var.count << std::endl;
    })

    DEBUG(for (auto& stmtCtx : semanticListener->programParser->stmts) {
        for (auto* ctx : stmtCtx) {
            std::cout << ctx->getText();
        }
        std::cout << '\n';
    });
}
} // namespace PrologCompiler
