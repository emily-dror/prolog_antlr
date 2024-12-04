#include "Visitors.hpp"
#include "ParserRuleContext.h"
#include "Token.h"
#include "Utils.hpp"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cctype>
#include <format>
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

std::any MarkEmptyTuplesVisitor::visitTuple(prologParser::TupleContext* ctx) {
    CHECK_NULL(ctx);

    // postorder
    visitChildren(ctx);

    auto entryVec = ctx->tuple_entry(); 

    bool isEmpty = true; // Base: if there are no entries then the for won't do any iteration.
    for(auto* entry : entryVec){
        auto* pTuple = entry->tuple();
        if(pTuple != nullptr){ // This is a tuple.
            if(empty.get(pTuple) == false){
                isEmpty = false;
                break;
            }
        }
    }

    empty.put(ctx, isEmpty);

    LOG(std::format("{}: {}",(isEmpty) ? "Empty" : "Not Empty",ctx->getText()));
    return {};
};

} // namespace Prolog::Visitors
