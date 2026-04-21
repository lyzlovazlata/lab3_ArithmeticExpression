#pragma once

#include "PascalBaseVisitor.h"
#include "MyTreeExpr.h"
#include "PascalLexer.h"
#include "PascalParser.h"

class TreeBuilderVisitor : public PascalBaseVisitor {
    vector<Expr*> statements;

    string getComparisonOp(PascalParser::ConditionContext* ctx) {
        if (ctx->LESS()) return "<";
        if (ctx->GREATER()) return ">";
        if (ctx->EQUALS()) return "==";
        if (ctx->LESS_EQ()) return "<=";
        if (ctx->GREATER_EQ()) return ">=";
        if (ctx->NOT_EQ()) return "!=";
        return "";
    }

    inline Expr* asExpr(any v) {
        return any_cast<Expr*>(v);
    }

public:

    any visitProgram(PascalParser::ProgramContext* ctx) override {
        for (auto stmt : ctx->statement()) {
            Expr* expr = asExpr(visit(stmt));
            if (expr)
                statements.push_back(expr);
        }

        if (statements.empty())
            return (Expr*)nullptr;

        Expr* root = statements[0];

        for (size_t i = 1; i < statements.size(); i++) {
            root = new SemicolonNode(root, statements[i]);
        }

        return (Expr*)root;
    }

    any visitStatement(PascalParser::StatementContext* ctx) override {
        if (ctx->assignment()) {
            return (Expr*)asExpr(visit(ctx->assignment()));
        }

        if (ctx->whileLoop()) {
            return (Expr*)asExpr(visit(ctx->whileLoop()));
        }

        if (ctx->expression()) {
            return (Expr*)asExpr(visit(ctx->expression()));
        }

        return (Expr*)nullptr;
    }

    any visitAssignment(PascalParser::AssignmentContext* ctx) override {
        string name = ctx->VARIABLE()->getText();

        Expr* var = (Expr*)new Variable(name);
        Expr* expr = asExpr(visit(ctx->expression()));

        return (Expr*)new Assignment(var, expr);
    }
	
    any visitWhileLoop(PascalParser::WhileLoopContext* ctx) override {
        Expr* condExpr = asExpr(visit(ctx->condition()));
        Condition* cond = (Condition*)condExpr;

        vector<Expr*> body;

        for (auto stmt : ctx->statement()) {
            Expr* e = asExpr(visit(stmt));
            if (e)
                body.push_back(e);
        }

        return (Expr*)new WhileNode(cond, body);
    }

    any visitCondition(PascalParser::ConditionContext* ctx) override {
        Expr* left = asExpr(visit(ctx->expression(0)));

        if (ctx->expression().size() == 1) {
            return (Expr*)new Condition(left, "", nullptr);
        }

        string op = getComparisonOp(ctx);
        Expr* right = asExpr(visit(ctx->expression(1)));

        return (Expr*)new Condition(left, op, right);
    }
	
    any visitExpression(PascalParser::ExpressionContext* ctx) override {
        Expr* node = asExpr(visit(ctx->term(0)));

        for (size_t i = 1; i < ctx->term().size(); i++) {
            string op = (i - 1 < ctx->PLUS().size() && ctx->PLUS(i - 1)) ? "+" : "-";

            Expr* right = asExpr(visit(ctx->term(i)));

            node = new BiOperation(op[0], node, right);
        }

        return (Expr*)node;
    }

    any visitTerm(PascalParser::TermContext* ctx) override {
        Expr* node = asExpr(visit(ctx->factor(0)));

        for (size_t i = 1; i < ctx->factor().size(); i++) {
            string op = (i - 1 < ctx->MULTIPLY().size() && ctx->MULTIPLY(i - 1)) ? "*" : "/";

            Expr* right = asExpr(visit(ctx->factor(i)));

            node = new BiOperation(op[0], node, right);
        }

        return (Expr*)node;
    }

    any visitFactor(PascalParser::FactorContext* ctx) override {
        if (ctx->INTEGER()) {
            Expr* n = new NumberNode(stoi(ctx->INTEGER()->getText()));
            return (Expr*)n;
        }

        if (ctx->DOUBLE()) {
            Expr* n = new NumberNode(stod(ctx->DOUBLE()->getText()));
            return (Expr*)n;
        }

        if (ctx->VARIABLE()) {
            Expr* v = new Variable(ctx->VARIABLE()->getText());
            return (Expr*)v;
        }

        if (ctx->expression()) {
            return visit(ctx->expression());
        }

        return (Expr*)nullptr;
    }

    Expr* getAST() {
        if (statements.empty())
            return nullptr;

        Expr* root = statements[0];

        for (size_t i = 1; i < statements.size(); i++) {
            root = new SemicolonNode(root, statements[i]);
        }

        return root;
    }

    ~TreeBuilderVisitor() {
        for (auto s : statements)
            delete s;
    }
};