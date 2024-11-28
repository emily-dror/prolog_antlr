#include "antlr4-runtime.h"
#include "prologLexer.h"
#include "prologParser.h"
#include "tree/ParseTree.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "Compiler.hpp"

using namespace antlr4;


int main(int argc, const char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
    }

    Prolog::Compiler compiler;
    compiler.compile(argv[1],{Prolog::Compiler::Flag::COMP_TO_PROLOG});

    return 0;
}
