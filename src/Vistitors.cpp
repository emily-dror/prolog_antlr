#include "Token.h"
#include "Visitors.hpp"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cctype>
#include "Utils.hpp"
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


std::any ProgramRestoreVisitor::visitCompound_term(prologParser::Compound_termContext *ctx){
    CHECK_NULL(ctx);
    programStmtList.back().push_back(ctx);
    return {};
}
std::any ProgramRestoreVisitor::visitTerminal(antlr4::tree::TerminalNode* ctx) {
    CHECK_NULL(ctx);

    if(ctx->getSymbol()->getType() != antlr4::Token::EOF){
        programStmtList.back().push_back(ctx);
    }

    return visitChildren(ctx);
}

std::any VariableSemanticVisitor::visitVariable(prologParser::VariableContext* ctx) {
    CHECK_NULL(ctx);

    const std::string& varName = ctx->getText();

    if (ctx->getText() == "_") {
        return {};
    }

    if (auto it = varTbl.find(varName); it != varTbl.end()) {
        auto& [_, var] = *it;
        auto& [varCtx, count] = var;
        if (count == MIN_VAR_COUNT) {
            invalidVars--;
        }
    } else {
        varTbl.insert({varName, {ctx, 1}});
        invalidVars++;
    }

    return visitChildren(ctx);
}

} // namespace Prolog::Visitors
