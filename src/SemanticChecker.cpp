#include "SemanticChecker.hpp"
#include "ANTLRFileStream.h"
#include "prologParser.h"
#include "tree/TerminalNode.h"
#include <cctype>
#include <map>
#include <memory>
namespace PrologCompiler {

void SemanticCheckListener::enterVariable(prologParser::VariableContext* ctx) {
    if (enabled(Listeners::VAR_L)) {
        varSemanticChecker->enterVariable(ctx);
    }
}

void SemanticCheckListener::exitEveryRule(antlr4::ParserRuleContext* ctx) {
    if(enabled(Listeners::PROG_PARSE_L)){
        programParser->exitEveryRule(ctx);
    }
}


bool SemanticCheckListener::enabled(Listeners listener) const {
    return enabledListeners.find(listener) != enabledListeners.end();
}

SemanticCheckListener::SemanticCheckListener(const std::set<Listeners>& listeners)
    : varSemanticChecker(std::make_unique<VariableSemanticListener>()),
      programParser(std::make_unique<ProgramParseListener>()),
      enabledListeners(listeners) {
}
void VariableSemanticListener::enterVariable(prologParser::VariableContext* ctx) {
    const std::string& varName = ctx->getText();

    if (ctx->getText() == "_") {
        return;
    }

    if (auto it = varTbl.find(varName); it != varTbl.end()) {
        auto& [_, var] = *it;
        var.count++;
        if (var.count == MIN_VAR_COUNT) {
            invalidVars--;
        }
    } else {
        Var var{ctx};
        varTbl.insert({varName, std::move(var)});
        invalidVars++;
    }
}

bool PrologCompiler::VariableSemanticListener::valid() const {
    return invalidVars == 0;
}
} // namespace PrologCompiler
