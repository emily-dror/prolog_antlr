#pragma once

#include "Parser.h"
#include "ParserRuleContext.h"
#include "prologBaseVisitor.h"
#include "prologParser.h"
#include "tree/ParseTreeProperty.h"
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

struct MarkEmptyTuplesVisitor : public prologBaseVisitor {
    antlr4::tree::ParseTreeProperty<bool> emptyTuples;
    std::any visitTuple(prologParser::TupleContext* ctx) override;
};

struct ProgramRestoreVisitor : public prologBaseVisitor {


    // NOTE: We can use std::variant for a cleaner code for clause/directive
    std::any visitClause(prologParser::ClauseContext* ctx) override;
    std::any visitDirective(prologParser::DirectiveContext* ctx) override;
    std::any visitCompound_term(prologParser::Compound_termContext* ctx) override;
    // NOTE: This method comes form the super class AbstractParseTreeVisitor
    std::any visitTerminal(antlr4::tree::TerminalNode* ctx) override;

    std::any visitTuple(prologParser::TupleContext* ctx) override;

    
    std::list<std::list<std::string>> programStmtList = {{}};
    std::optional<antlr4::tree::ParseTreeProperty<bool>> emptyTuples;
};


} // namespace Prolog::Visitors
