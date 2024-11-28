#pragma once

#include "ParserRuleContext.h"
#include "Token.h"
#include "Utils.hpp"
#include "prologBaseListener.h"
#include "prologBaseVisitor.h"
#include "prologParser.h"
#include "tree/ParseTree.h"
#include "tree/TerminalNode.h"
#include <array>
#include <list>
#include <bitset>
#include <memory>

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

    // Note that this method comes form the super classAbstractParseTreeVisitor
    std::any visitTerminal(antlr4::tree::TerminalNode* ctx) override;

    std::list<std::list<antlr4::tree::TerminalNode*>> programList = {{}};
};

} // namespace PrologCompiler
