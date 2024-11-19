
// Generated from grammar/prolog.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "prologParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by prologParser.
 */
class  prologListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterP_text(prologParser::P_textContext *ctx) = 0;
  virtual void exitP_text(prologParser::P_textContext *ctx) = 0;

  virtual void enterDirective(prologParser::DirectiveContext *ctx) = 0;
  virtual void exitDirective(prologParser::DirectiveContext *ctx) = 0;

  virtual void enterClause(prologParser::ClauseContext *ctx) = 0;
  virtual void exitClause(prologParser::ClauseContext *ctx) = 0;

  virtual void enterTermlist(prologParser::TermlistContext *ctx) = 0;
  virtual void exitTermlist(prologParser::TermlistContext *ctx) = 0;

  virtual void enterAtom_term(prologParser::Atom_termContext *ctx) = 0;
  virtual void exitAtom_term(prologParser::Atom_termContext *ctx) = 0;

  virtual void enterBinary_operator(prologParser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(prologParser::Binary_operatorContext *ctx) = 0;

  virtual void enterUnary_operator(prologParser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(prologParser::Unary_operatorContext *ctx) = 0;

  virtual void enterBraced_term(prologParser::Braced_termContext *ctx) = 0;
  virtual void exitBraced_term(prologParser::Braced_termContext *ctx) = 0;

  virtual void enterList_term(prologParser::List_termContext *ctx) = 0;
  virtual void exitList_term(prologParser::List_termContext *ctx) = 0;

  virtual void enterVariable(prologParser::VariableContext *ctx) = 0;
  virtual void exitVariable(prologParser::VariableContext *ctx) = 0;

  virtual void enterFloat(prologParser::FloatContext *ctx) = 0;
  virtual void exitFloat(prologParser::FloatContext *ctx) = 0;

  virtual void enterCompound_term(prologParser::Compound_termContext *ctx) = 0;
  virtual void exitCompound_term(prologParser::Compound_termContext *ctx) = 0;

  virtual void enterInteger_term(prologParser::Integer_termContext *ctx) = 0;
  virtual void exitInteger_term(prologParser::Integer_termContext *ctx) = 0;

  virtual void enterCurly_bracketed_term(prologParser::Curly_bracketed_termContext *ctx) = 0;
  virtual void exitCurly_bracketed_term(prologParser::Curly_bracketed_termContext *ctx) = 0;

  virtual void enterOperator_(prologParser::Operator_Context *ctx) = 0;
  virtual void exitOperator_(prologParser::Operator_Context *ctx) = 0;

  virtual void enterEmpty_list(prologParser::Empty_listContext *ctx) = 0;
  virtual void exitEmpty_list(prologParser::Empty_listContext *ctx) = 0;

  virtual void enterEmpty_braces(prologParser::Empty_bracesContext *ctx) = 0;
  virtual void exitEmpty_braces(prologParser::Empty_bracesContext *ctx) = 0;

  virtual void enterName(prologParser::NameContext *ctx) = 0;
  virtual void exitName(prologParser::NameContext *ctx) = 0;

  virtual void enterGraphic(prologParser::GraphicContext *ctx) = 0;
  virtual void exitGraphic(prologParser::GraphicContext *ctx) = 0;

  virtual void enterQuoted_string(prologParser::Quoted_stringContext *ctx) = 0;
  virtual void exitQuoted_string(prologParser::Quoted_stringContext *ctx) = 0;

  virtual void enterDq_string(prologParser::Dq_stringContext *ctx) = 0;
  virtual void exitDq_string(prologParser::Dq_stringContext *ctx) = 0;

  virtual void enterBackq_string(prologParser::Backq_stringContext *ctx) = 0;
  virtual void exitBackq_string(prologParser::Backq_stringContext *ctx) = 0;

  virtual void enterSemicolon(prologParser::SemicolonContext *ctx) = 0;
  virtual void exitSemicolon(prologParser::SemicolonContext *ctx) = 0;

  virtual void enterCut(prologParser::CutContext *ctx) = 0;
  virtual void exitCut(prologParser::CutContext *ctx) = 0;

  virtual void enterInteger(prologParser::IntegerContext *ctx) = 0;
  virtual void exitInteger(prologParser::IntegerContext *ctx) = 0;


};

