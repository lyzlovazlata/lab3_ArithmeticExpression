#pragma once

#include "PascalBaseVisitor.h"
#include "MyTreeExpr.h"
#include "PascalLexer.h"
#include "PascalParser.h"

class TreeBuilderVisitor : public PascalBaseVisitor {
    vector<Expr*> statements;
    Expr* chainStatements(const vector<Expr*>& nodes) {
        if (nodes.empty()) return nullptr;
        Expr* root = nodes[0];
        for (size_t i = 1; i < nodes.size(); i++) {
            root = new Semicol(root, nodes[i]);
        }
        return root;
    }
    string comp(PascalParser::ConditionContext* ctx) {
        if (ctx->LESS()) return "<";
        else if (ctx->GREATER()) return ">";
        else if (ctx->EQUALS()) return "=";
        else if (ctx->LESS_EQ()) return "<=";
        else if (ctx->GREATER_EQ()) return ">=";
        else if (ctx->NOT_EQ()) return "!=";
        else return "";
    }
    inline Expr* toexp(any v) {return any_cast<Expr*>(v);}

public:

    any visitProgram(PascalParser::ProgramContext* ctx) override {

        // с корня рекурсивно заходим во все
        for (auto stmt : ctx->statement()) {
            Expr* expr = toexp(visit(stmt));
            if (expr) statements.push_back(expr);
        }

        return (Expr*)chainStatements(statements);
    }

    any visitStatement(PascalParser::StatementContext* ctx) override {
        if (ctx->assignment()) {
            return (Expr*)toexp(visit(ctx->assignment()));
        }

        if (ctx->whileLoop()) {
            return (Expr*)toexp(visit(ctx->whileLoop()));
        }
        if (ctx->ifcond()) {
            return (Expr*)toexp(visit(ctx->ifcond()));
        }

        if (ctx->expression()) {
            return (Expr*)toexp(visit(ctx->expression()));
        }

        return (Expr*)nullptr;
    }

    any visitAssignment(PascalParser::AssignmentContext* ctx) override {
        string name = ctx->VARIABLE()->getText();

        Expr* var = (Expr*)new Variable(name);
        Expr* expr = toexp(visit(ctx->expression()));

        return (Expr*)new Assignment(var, expr);
    }
	
    any visitWhileLoop(PascalParser::WhileLoopContext* ctx) override {
        Expr* condExpr = toexp(visit(ctx->condition()));
        Cond* cond = (Cond*)condExpr;

        vector<Expr*> body;

        for (auto stmt : ctx->statement()) {
            Expr* e = toexp(visit(stmt));
            if (e) body.push_back(e);
        }

        return (Expr*)new While(cond, chainStatements(body));
    }

    any visitIfcond(PascalParser::IfcondContext* ctx) override {
        Expr* condExpr = toexp(visit(ctx->condition()));
        Cond* cond = dynamic_cast<Cond*>(condExpr);

        vector<Expr*> thenBody;
        vector<Expr*> elseBody;

        for (auto stmt : ctx->thenBranch->statement()) {
            Expr* e = toexp(visit(stmt));
            if (e) thenBody.push_back(e);
        }

        if (ctx->elseBranch != nullptr) {
            for (auto stmt : ctx->elseBranch->statement()) {
                Expr* e = toexp(visit(stmt));
                if (e) elseBody.push_back(e);
            }
        }

        return (Expr*)new IfCond(cond, chainStatements(thenBody), chainStatements(elseBody));
    }
    any visitCondition(PascalParser::ConditionContext* ctx) override {
        Expr* left = toexp(visit(ctx->expression(0)));
        if (ctx->expression().size() == 1) {
            return (Expr*)new Cond(left, "", nullptr);
        }
        string op = comp(ctx);
        Expr* right = toexp(visit(ctx->expression(1)));
        return (Expr*)new Cond(left, op, right);
    }
	
    any visitExpression(PascalParser::ExpressionContext* ctx) override {
        Expr* node = toexp(visit(ctx->term(0)));

        for (size_t i = 1; i < ctx->term().size(); i++) {
            string op;
            if (i - 1 < ctx->PLUS().size() && ctx->PLUS(i - 1)) {
                op = "+";
            }
            else if (i - 1 < ctx->MINUS().size() && ctx->MINUS(i - 1)) {
                op = "-";
            }

            Expr* right = toexp(visit(ctx->term(i)));
            node = new BiOperation(op[0], node, right);
        }

        return (Expr*)node;
    }

    any visitTerm(PascalParser::TermContext* ctx) override {
        Expr* node = toexp(visit(ctx->factor(0)));

        for (size_t i = 1; i < ctx->factor().size(); i++) {
            string op;
            if (i - 1 < ctx->MULTIPLY().size() && ctx->MULTIPLY(i - 1)) {
                op = "*";
            }
            else if (i - 1 < ctx->DEVIDE().size() && ctx->DEVIDE(i - 1)) {
                op = "/";
            }

            Expr* right = toexp(visit(ctx->factor(i)));
            node = new BiOperation(op[0], node, right);
        }

        return (Expr*)node;
    }

    any visitFactor(PascalParser::FactorContext* ctx) override {
        if (ctx->INTEGER()) {
            Expr* n = new Number(stoi(ctx->INTEGER()->getText()));
            return (Expr*)n;
        }

        if (ctx->DOUBLE()) {
            Expr* n = new Number(stod(ctx->DOUBLE()->getText()));
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

};
