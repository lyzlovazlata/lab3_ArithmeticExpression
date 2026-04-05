
// Generated from Pascal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalVisitor.h"


/**
 * This class provides an empty implementation of PascalVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PascalBaseVisitor : public PascalVisitor {
public:

  virtual std::any visitProgram(PascalParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(PascalParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(PascalParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileLoop(PascalParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCondition(PascalParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(PascalParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(PascalParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(PascalParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

