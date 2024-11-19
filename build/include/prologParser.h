
// Generated from grammar/prolog.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  prologParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, LETTER_DIGIT = 52, VARIABLE = 53, DECIMAL = 54, BINARY = 55, 
    OCTAL = 56, HEX = 57, CHARACTER_CODE_CONSTANT = 58, FLOAT = 59, GRAPHIC_TOKEN = 60, 
    QUOTED = 61, DOUBLE_QUOTED_LIST = 62, BACK_QUOTED_STRING = 63, WS = 64, 
    COMMENT = 65, MULTILINE_COMMENT = 66
  };

  enum {
    RuleP_text = 0, RuleDirective = 1, RuleClause = 2, RuleTermlist = 3, 
    RuleTerm = 4, RuleOperator_ = 5, RuleAtom = 6, RuleInteger = 7
  };

  explicit prologParser(antlr4::TokenStream *input);

  prologParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~prologParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class P_textContext;
  class DirectiveContext;
  class ClauseContext;
  class TermlistContext;
  class TermContext;
  class Operator_Context;
  class AtomContext;
  class IntegerContext; 

  class  P_textContext : public antlr4::ParserRuleContext {
  public:
    P_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DirectiveContext *> directive();
    DirectiveContext* directive(size_t i);
    std::vector<ClauseContext *> clause();
    ClauseContext* clause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  P_textContext* p_text();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DirectiveContext* directive();

  class  ClauseContext : public antlr4::ParserRuleContext {
  public:
    ClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ClauseContext* clause();

  class  TermlistContext : public antlr4::ParserRuleContext {
  public:
    TermlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermlistContext* termlist();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_termContext : public TermContext {
  public:
    Atom_termContext(TermContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Binary_operatorContext : public TermContext {
  public:
    Binary_operatorContext(TermContext *ctx);

    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    Operator_Context *operator_();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Unary_operatorContext : public TermContext {
  public:
    Unary_operatorContext(TermContext *ctx);

    Operator_Context *operator_();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Braced_termContext : public TermContext {
  public:
    Braced_termContext(TermContext *ctx);

    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  List_termContext : public TermContext {
  public:
    List_termContext(TermContext *ctx);

    TermlistContext *termlist();
    TermContext *term();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  VariableContext : public TermContext {
  public:
    VariableContext(TermContext *ctx);

    antlr4::tree::TerminalNode *VARIABLE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  FloatContext : public TermContext {
  public:
    FloatContext(TermContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Compound_termContext : public TermContext {
  public:
    Compound_termContext(TermContext *ctx);

    AtomContext *atom();
    TermlistContext *termlist();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Integer_termContext : public TermContext {
  public:
    Integer_termContext(TermContext *ctx);

    IntegerContext *integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Curly_bracketed_termContext : public TermContext {
  public:
    Curly_bracketed_termContext(TermContext *ctx);

    TermlistContext *termlist();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Operator_Context : public antlr4::ParserRuleContext {
  public:
    Operator_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Operator_Context* operator_();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AtomContext() = default;
    void copyFrom(AtomContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Backq_stringContext : public AtomContext {
  public:
    Backq_stringContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *BACK_QUOTED_STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  CutContext : public AtomContext {
  public:
    CutContext(AtomContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Empty_bracesContext : public AtomContext {
  public:
    Empty_bracesContext(AtomContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Dq_stringContext : public AtomContext {
  public:
    Dq_stringContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE_QUOTED_LIST();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  NameContext : public AtomContext {
  public:
    NameContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *LETTER_DIGIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Quoted_stringContext : public AtomContext {
  public:
    Quoted_stringContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *QUOTED();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Empty_listContext : public AtomContext {
  public:
    Empty_listContext(AtomContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  GraphicContext : public AtomContext {
  public:
    GraphicContext(AtomContext *ctx);

    antlr4::tree::TerminalNode *GRAPHIC_TOKEN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SemicolonContext : public AtomContext {
  public:
    SemicolonContext(AtomContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  AtomContext* atom();

  class  IntegerContext : public antlr4::ParserRuleContext {
  public:
    IntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *CHARACTER_CODE_CONSTANT();
    antlr4::tree::TerminalNode *BINARY();
    antlr4::tree::TerminalNode *OCTAL();
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntegerContext* integer();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool termSempred(TermContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

