
// Generated from Pascal.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PascalParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PascalParser.
 */
class  PascalVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PascalParser.
   */
    virtual std::any visitProgram(PascalParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(PascalParser::StatementContext *context) = 0;

    virtual std::any visitAssignment(PascalParser::AssignmentContext *context) = 0;

    virtual std::any visitWhileLoop(PascalParser::WhileLoopContext *context) = 0;

    virtual std::any visitCondition(PascalParser::ConditionContext *context) = 0;

    virtual std::any visitExpression(PascalParser::ExpressionContext *context) = 0;

    virtual std::any visitTerm(PascalParser::TermContext *context) = 0;

    virtual std::any visitFactor(PascalParser::FactorContext *context) = 0;


};

