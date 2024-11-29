#pragma once

#include "ParserRuleContext.h"
#include "prologBaseVisitor.h"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <list>
#include <variant>

namespace Prolog::Visitors {

struct VariableSemanticVisitor : public prologBaseVisitor {
    std::any visitVariable(prologParser::VariableContext* ctx) override;

    std::map<std::string, std::pair<prologParser::VariableContext*, std::size_t>> varTbl;
    std::size_t invalidVars = 0;
    static constexpr std::size_t MIN_VAR_COUNT = 2;
};

struct ProgramRestoreVisitor : public prologBaseVisitor {

    // NOTE: We can use std::variant for a cleaner code for clause/directive
    std::any visitClause(prologParser::ClauseContext* ctx) override;
    std::any visitDirective(prologParser::DirectiveContext* ctx) override;
    std::any visitCompound_term(prologParser::Compound_termContext* ctx) override;
    // NOTE: This method comes form the super class AbstractParseTreeVisitor
    std::any visitTerminal(antlr4::tree::TerminalNode* ctx) override;

    using ProgramNode = std::variant<antlr4::tree::TerminalNode*, antlr4::ParserRuleContext*>;

    std::list<std::list<ProgramNode>> programStmtList = {{}};
};

} // namespace Prolog::Visitors
