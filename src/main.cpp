#include <iostream>
#include "Compiler.hpp"
#include "gtest.h"

using namespace antlr4;

int main(int argc, const char** argv) {
    if (argc < 2) {
        testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    } else {
        Prolog::Compiler compiler;
        compiler.compile(argv[1],{Prolog::Compiler::Flag::COMP_TO_PROLOG});
        return 0;
    }
}
