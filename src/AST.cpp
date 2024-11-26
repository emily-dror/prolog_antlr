#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "prologLexer.h"
#include "prologParser.h"

using namespace antlr4;

int main(int argc, const char* argv[]) {
    // Check input file
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
    }
    // Open input file
    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    // Create ANTLR input stream
    ANTLRInputStream input(inputFile);

    // Create Lexer and TokenStream
    prologLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // Create Parser
    prologParser parser(&tokens);

    // Parse (start from the root rule of your grammar)
    tree::ParseTree* tree = parser.p_text();

    // Print the parsed tree (optional)
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}

