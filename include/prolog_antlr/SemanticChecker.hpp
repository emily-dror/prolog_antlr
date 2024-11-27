#pragma once

#include "ParserRuleContext.h"
#include "Token.h"
#include "prologBaseListener.h"
#include "prologParser.h"
#include "tree/ParseTree.h"
#include <array>
#include <bitset>
#include <memory>

#define ENABLE_DEBUG 1

#if defined(ENABLE_DEBUG) && ENABLE_DEBUG == 1
#define DEBUG(line) line
#define LOG(line) std::cout << "(" << __FUNCTION__ << "," << __LINE__ << "):" << line << std::endl
#else
#define DEBUG(line)
#define LOG(line)
#endif

namespace PrologCompiler {

struct Var {
    prologParser::VariableContext* varCtx;
    std::size_t count = 1;
};

struct ProgramParseListener : public prologBaseListener {
    std::vector<std::vector<antlr4::tree::ParseTree*>> stmts = {{}};
    void exitEveryRule(antlr4::ParserRuleContext* ctx) override;
};

struct VariableSemanticListener : public prologBaseListener {
    void enterVariable(prologParser::VariableContext* ctx) override;
    bool valid() const;

    std::map<std::string, Var> varTbl;
    std::size_t invalidVars = 0;
    static constexpr std::size_t MIN_VAR_COUNT = 2;
};

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
