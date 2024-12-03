#include "Token.h"
#include "Utils.hpp"
#include "Visitors.hpp"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cctype>
#include <map>

namespace Prolog::Visitors {

std::any ProgramRestoreVisitor::visitClause(prologParser::ClauseContext* ctx) {
    CHECK_NULL(ctx);

    programStmtList.push_back({});

    return visitChildren(ctx);
}

std::any ProgramRestoreVisitor::visitDirective(prologParser::DirectiveContext* ctx) {
    CHECK_NULL(ctx);

    programStmtList.push_back({});

    return visitChildren(ctx);
}

std::any ProgramRestoreVisitor::visitCompound_term(prologParser::Compound_termContext* ctx) {
    CHECK_NULL(ctx);
    programStmtList.back().push_back(ctx);
    return {};
}
std::any ProgramRestoreVisitor::visitTerminal(antlr4::tree::TerminalNode* ctx) {
    CHECK_NULL(ctx);

    if (ctx->getSymbol()->getType() != antlr4::Token::EOF) {
        programStmtList.back().push_back(ctx);
    }

    return visitChildren(ctx);
}

std::any VariableSemanticVisitor::visitVariable(prologParser::VariableContext* ctx) {
    CHECK_NULL(ctx);

    const std::string& varName = ctx->getText();

    if (varName == "_") {
        return visitChildren(ctx);
    }

    if (auto it = varTbl.find(varName); it != varTbl.end()) {
        auto& [_, count] = *it;
        ++count;
    } else {
        varTbl.insert({varName, 1});
    }

    return visitChildren(ctx);
}

} // namespace Prolog::Visitors
