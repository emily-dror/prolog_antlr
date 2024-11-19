
// Generated from grammar/prolog.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "prologListener.h"


/**
 * This class provides an empty implementation of prologListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  prologBaseListener : public prologListener {
public:

  virtual void enterP_text(prologParser::P_textContext * /*ctx*/) override { }
  virtual void exitP_text(prologParser::P_textContext * /*ctx*/) override { }

  virtual void enterDirective(prologParser::DirectiveContext * /*ctx*/) override { }
  virtual void exitDirective(prologParser::DirectiveContext * /*ctx*/) override { }

  virtual void enterClause(prologParser::ClauseContext * /*ctx*/) override { }
  virtual void exitClause(prologParser::ClauseContext * /*ctx*/) override { }

  virtual void enterTermlist(prologParser::TermlistContext * /*ctx*/) override { }
  virtual void exitTermlist(prologParser::TermlistContext * /*ctx*/) override { }

  virtual void enterAtom_term(prologParser::Atom_termContext * /*ctx*/) override { }
  virtual void exitAtom_term(prologParser::Atom_termContext * /*ctx*/) override { }

  virtual void enterBinary_operator(prologParser::Binary_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_operator(prologParser::Binary_operatorContext * /*ctx*/) override { }

  virtual void enterUnary_operator(prologParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(prologParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterBraced_term(prologParser::Braced_termContext * /*ctx*/) override { }
  virtual void exitBraced_term(prologParser::Braced_termContext * /*ctx*/) override { }

  virtual void enterList_term(prologParser::List_termContext * /*ctx*/) override { }
  virtual void exitList_term(prologParser::List_termContext * /*ctx*/) override { }

  virtual void enterVariable(prologParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(prologParser::VariableContext * /*ctx*/) override { }

  virtual void enterFloat(prologParser::FloatContext * /*ctx*/) override { }
  virtual void exitFloat(prologParser::FloatContext * /*ctx*/) override { }

  virtual void enterCompound_term(prologParser::Compound_termContext * /*ctx*/) override { }
  virtual void exitCompound_term(prologParser::Compound_termContext * /*ctx*/) override { }

  virtual void enterInteger_term(prologParser::Integer_termContext * /*ctx*/) override { }
  virtual void exitInteger_term(prologParser::Integer_termContext * /*ctx*/) override { }

  virtual void enterCurly_bracketed_term(prologParser::Curly_bracketed_termContext * /*ctx*/) override { }
  virtual void exitCurly_bracketed_term(prologParser::Curly_bracketed_termContext * /*ctx*/) override { }

  virtual void enterOperator_(prologParser::Operator_Context * /*ctx*/) override { }
  virtual void exitOperator_(prologParser::Operator_Context * /*ctx*/) override { }

  virtual void enterEmpty_list(prologParser::Empty_listContext * /*ctx*/) override { }
  virtual void exitEmpty_list(prologParser::Empty_listContext * /*ctx*/) override { }

  virtual void enterEmpty_braces(prologParser::Empty_bracesContext * /*ctx*/) override { }
  virtual void exitEmpty_braces(prologParser::Empty_bracesContext * /*ctx*/) override { }

  virtual void enterName(prologParser::NameContext * /*ctx*/) override { }
  virtual void exitName(prologParser::NameContext * /*ctx*/) override { }

  virtual void enterGraphic(prologParser::GraphicContext * /*ctx*/) override { }
  virtual void exitGraphic(prologParser::GraphicContext * /*ctx*/) override { }

  virtual void enterQuoted_string(prologParser::Quoted_stringContext * /*ctx*/) override { }
  virtual void exitQuoted_string(prologParser::Quoted_stringContext * /*ctx*/) override { }

  virtual void enterDq_string(prologParser::Dq_stringContext * /*ctx*/) override { }
  virtual void exitDq_string(prologParser::Dq_stringContext * /*ctx*/) override { }

  virtual void enterBackq_string(prologParser::Backq_stringContext * /*ctx*/) override { }
  virtual void exitBackq_string(prologParser::Backq_stringContext * /*ctx*/) override { }

  virtual void enterSemicolon(prologParser::SemicolonContext * /*ctx*/) override { }
  virtual void exitSemicolon(prologParser::SemicolonContext * /*ctx*/) override { }

  virtual void enterCut(prologParser::CutContext * /*ctx*/) override { }
  virtual void exitCut(prologParser::CutContext * /*ctx*/) override { }

  virtual void enterInteger(prologParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(prologParser::IntegerContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

