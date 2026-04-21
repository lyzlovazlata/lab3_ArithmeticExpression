#pragma once
#include <iostream>
#include <any>
#include <string>
#include <vector>
#include "IMap.h"

using namespace std;

class Expr;
class NumberNode;
class BiOperation;
class SemicolonNode;
class Variable;
class Assignment;
class Condition;
class WhileNode;


class Visitor {
public:
    virtual double visitNumber(NumberNode* num) = 0;
    virtual double visitBiOperation(BiOperation* op) = 0;
    virtual void visitSemicolon(SemicolonNode* sem) = 0;
    virtual double visitVariable(Variable* var) = 0;
    virtual void visitAssignment(Assignment* as) = 0;
    virtual bool visitCondition(Condition* cond) = 0;
    virtual void visitWhile(WhileNode* wh) = 0;
    virtual ~Visitor() {}
};


class Expr {
public:
    virtual any accept(Visitor* v) = 0;
    virtual ~Expr() {}
};


class NumberNode : public Expr {
    double val;

public:
    NumberNode(int v) : val(v) {}
    NumberNode(double v) : val(v) {}

    double getVal() { return val; }

    any accept(Visitor* v) override {
        return v->visitNumber(this);
    }
};


class Variable : public Expr {
    string name;

public:
    Variable(string n) : name(n) {}

    string var() { return name; }

    any accept(Visitor* v) override {
        return v->visitVariable(this);
    }
};


class BiOperation : public Expr {
    char op_;
    Expr* left_;
    Expr* right_;

public:
    BiOperation(char op, Expr* l, Expr* r)
        : op_(op), left_(l), right_(r) {
    }

    ~BiOperation() {
        delete left_;
        delete right_;
    }

    char op() { return op_; }
    Expr* left() { return left_; }
    Expr* right() { return right_; }

    any accept(Visitor* v) override {
        return v->visitBiOperation(this);
    }
};


class Assignment : public Expr {
    Expr* left_;
    Expr* right_;

public:
    Assignment(Expr* l, Expr* r)
        : left_(l), right_(r) {
    }

    ~Assignment() {
        delete left_;
        delete right_;
    }

    Expr* left() { return left_; }
    Expr* right() { return right_; }

    any accept(Visitor* v) override {
        v->visitAssignment(this);
        return {};
    }
};


class SemicolonNode : public Expr {
    Expr* left_;
    Expr* right_;

public:
    SemicolonNode(Expr* l, Expr* r)
        : left_(l), right_(r) {
    }

    ~SemicolonNode() {
        delete left_;
        delete right_;
    }

    Expr* left() { return left_; }
    Expr* right() { return right_; }

    any accept(Visitor* v) override {
        v->visitSemicolon(this);
        return {};
    }
};


class Condition : public Expr {
    string op_;
    Expr* left_;
    Expr* right_;

public:
    Condition(Expr* l, string op, Expr* r)
        : left_(l), right_(r), op_(op) {
    }

    ~Condition() {
        delete left_;
        delete right_;
    }

    Expr* left() { return left_; }
    Expr* right() { return right_; }
    string znak() { return op_; }

    any accept(Visitor* v) override {
        return v->visitCondition(this);
    }
};


class WhileNode : public Expr {
    Condition* cond_;
    vector<Expr*> body_;

public:
    WhileNode(Condition* c, vector<Expr*> b)
        : cond_(c), body_(b) {
    }

    ~WhileNode() {
        delete cond_;
        for (auto x : body_)
            delete x;
    }

    Condition* getCondition() { return cond_; }
    vector<Expr*>& getBody() { return body_; }

    any accept(Visitor* v) override {
        v->visitWhile(this);
        return {};
    }
};


class CalcVisitor : public Visitor {
    IMap<string, double>* vars;

public:
    CalcVisitor(IMap<string, double>* m)
        : vars(m) {
    }

    double visitNumber(NumberNode* num) override {
        return num->getVal();
    }

    double visitVariable(Variable* var) override {
        return *vars->get(var->var());
    }

    double visitBiOperation(BiOperation* op) override {
        double l = any_cast<double>(op->left()->accept(this));
        double r = any_cast<double>(op->right()->accept(this));

        switch (op->op()) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
        }

        return 0;
    }

    void visitAssignment(Assignment* as) override {
        Variable* v = dynamic_cast<Variable*>(as->left());

        string name = v->var();
        double value = any_cast<double>(as->right()->accept(this));

        vars->insert(name, value);
    }

    void visitSemicolon(SemicolonNode* sem) override {
        sem->left()->accept(this);
        sem->right()->accept(this);
    }

    bool visitCondition(Condition* cond) override {
        double l = any_cast<double>(cond->left()->accept(this));

        if (cond->right() == nullptr)
            return l != 0;

        double r = any_cast<double>(cond->right()->accept(this));

        string op = cond->znak();

        if (op == "<") return l < r;
        if (op == ">") return l > r;
        if (op == "==") return l == r;
        if (op == "<=") return l <= r;
        if (op == ">=") return l >= r;
        if (op == "!=") return l != r;

        return false;
    }

    void visitWhile(WhileNode* wh) override {
        while (any_cast<bool>(wh->getCondition()->accept(this))) {
            for (auto stmt : wh->getBody())
                stmt->accept(this);
        }
    }
};

class PrintVisitor : public Visitor {
public:
    double visitNumber(NumberNode* num) override {
        cout << num->getVal();
        return 0;
    }

    double visitVariable(Variable* var) override {
        cout << var->var();
        return 0;
    }

    double visitBiOperation(BiOperation* op) override {
        cout << "(";
        op->left()->accept(this);
        cout << " " << op->op() << " ";
        op->right()->accept(this);
        cout << ")";
        return 0;
    }

    void visitAssignment(Assignment* as) override {
        as->left()->accept(this);
        cout << " = ";
        as->right()->accept(this);
    }

    void visitSemicolon(SemicolonNode* sem) override {
        sem->left()->accept(this);
        cout << "; ";
        if (sem->right() != nullptr) {
            sem->right()->accept(this);
        }
    }

    bool visitCondition(Condition* cond) override {
        cond->left()->accept(this);

        if (cond->right()) {
            cout << " " << cond->znak() << " ";
            cond->right()->accept(this);
        }

        return false;
    }

    void visitWhile(WhileNode* wh) override {
        cout << "while (";
        wh->getCondition()->accept(this);
        cout << ") do ";

        for (auto stmt : wh->getBody()) {
            stmt->accept(this);
            cout << "; ";
        }

        cout << "end";
    }
};


class PrintPostfixVisitor : public Visitor {
public:
    double visitNumber(NumberNode* num) override {
        cout << num->getVal() << " ";
        return 0;
    }

    double visitVariable(Variable* var) override {
        cout << var->var() << " ";
        return 0;
    }

    double visitBiOperation(BiOperation* op) override {
        op->left()->accept(this);
        op->right()->accept(this);
        cout << op->op() << " ";
        return 0;
    }

    void visitAssignment(Assignment* as) override {
        as->left()->accept(this);
        as->right()->accept(this);
        cout << "= ";
    }

    void visitSemicolon(SemicolonNode* sem) override {
        sem->left()->accept(this);
        cout << "; ";
        if (sem->right() != nullptr) {
            sem->right()->accept(this);
        }
    }

    bool visitCondition(Condition* cond) override {
        cond->left()->accept(this);

        if (cond->right())
            cond->right()->accept(this);

        cout << cond->znak() << " ";
        return false;
    }

    void visitWhile(WhileNode* wh) override {
        wh->getCondition()->accept(this);

        for (auto stmt : wh->getBody())
            stmt->accept(this);

        cout << "while ";
    }
};