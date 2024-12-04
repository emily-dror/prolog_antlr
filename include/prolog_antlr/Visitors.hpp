#pragma once

#include "Parser.h"
#include "ParserRuleContext.h"
#include "prologBaseVisitor.h"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cstdint>
#include <list>
#include <set>
#include <variant>

namespace Prolog::Visitors {

struct VariableSemanticVisitor : public prologBaseVisitor {
    std::any visitVariable(prologParser::VariableContext* ctx) override;

    std::map<std::string, std::uint8_t> varTbl;
    static constexpr std::size_t VAR_COUNT = 2;
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

struct MarkEmptyTuplesVisitor : public prologBaseVisitor {
    antlr4::tree::ParseTreeProperty<bool> empty;
    std::map<antlr4::ParserRuleContext, bool> rulesMap;
    std::any visitTuple(prologParser::TupleContext* ctx) override;
};

} // namespace Prolog::Visitors
