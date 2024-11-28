#pragma once

#include "ParserRuleContext.h"
#include "Token.h"
#include "prologBaseListener.h"
#include "prologParser.h"
#include "tree/ParseTree.h"
#include <array>
#include <bitset>
#include <memory>
#include "Utils.hpp"


namespace PrologCompiler {

struct Var {
    prologParser::VariableContext* varCtx;
    std::size_t count = 1;
};

struct ProgramParseListener : public prologBaseListener {
    std::vector<std::vector<antlr4::tree::ParseTree*>> stmts = {{}};
    void exitEveryRule(antlr4::ParserRuleContext* ctx) override;
};

/**
 * @class VariableSemanticListener
 * @brief For checking additional semanics of variables.
 *
 */
struct VariableSemanticListener : public prologBaseListener {
    void enterVariable(prologParser::VariableContext* ctx) override;
    bool valid() const;

    std::map<std::string, Var> varTbl;
    std::size_t invalidVars = 0;
    static constexpr std::size_t MIN_VAR_COUNT = 2;
};

/**
 * @class SemanticCheckListener
 * @brief This is a composite class, add any listener, call it on the function you want.
 * Uses: Doing multiple semantic checks in one tree walk.
 *
 */
struct SemanticCheckListener : prologBaseListener {
    enum class Listeners {
        VAR_L = 0,
        PROG_PARSE_L,
    };

    std::unique_ptr<VariableSemanticListener> varSemanticChecker;
    std::unique_ptr<ProgramParseListener> programParser;
    std::set<Listeners> enabledListeners;

    SemanticCheckListener(const std::set<Listeners>& listeners);

    bool enabled(Listeners listener) const;
    void enterVariable(prologParser::VariableContext* ctx) override;
    void exitEveryRule(antlr4::ParserRuleContext* ctx) override;
};

} // namespace PrologCompiler
