#include "Visitors.hpp"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cctype>
#include <map>

namespace Prolog::Visitors {

std::any ProgramRestoreVisitor::visitClause(prologParser::ClauseContext* ctx) {
    if (ctx == nullptr) {
        LOG("nullptr");
    }

    programList.push_back({});

    return visitChildren(ctx);
}

std::any ProgramRestoreVisitor::visitDirective(prologParser::DirectiveContext* ctx) {
    if (ctx == nullptr) {
        LOG("nullptr");
    }

    programList.push_back({});

    return visitChildren(ctx);
}

std::any ProgramRestoreVisitor::visitTerminal(antlr4::tree::TerminalNode* ctx) {

    if (ctx == nullptr) {
        LOG("nullptr");
    }

    programList.back().push_back(ctx);
    return visitChildren(ctx);
}

std::any VariableSemanticVisitor::visitVariable(prologParser::VariableContext* ctx) {
    if (ctx == nullptr) {
        LOG("Nullptr");
    }

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

} // namespace PrologCompiler
