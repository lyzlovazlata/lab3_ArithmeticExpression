#pragma once
#include <iostream>
#include <any>
#include <string>
#include <vector>
#include "IMap.h"

using namespace std;
class Number;
class BiOperation;
class Variable;
class Assignment;
class Expr;
class Semicol;
class Cond;
class While;


class Visitor {
public:
    virtual double visitNumber(Number* num) = 0;
    virtual double visitBiOperation(BiOperation* op) = 0;
    virtual void visitAssignment(Assignment* as) = 0;    
    virtual bool visitCondition(Cond* cond) = 0;
    virtual void visitWhile(While* wh) = 0;
    virtual void visitSemicolon(Semicol* sem) = 0;
    virtual double visitVariable(Variable* var) = 0;
    virtual ~Visitor() {}
};


class Expr {
public:
    virtual any accept(Visitor* v) = 0;
    virtual ~Expr() {}
};

class BiOperation : public Expr {
    char op_;
    Expr* lef;
    Expr* ri;

public:
    BiOperation(char op, Expr* l, Expr* r)
        : op_(op), lef(l), ri(r) {
    }

    ~BiOperation() {
        delete lef;
        delete ri;
    }

    char op() { return op_; }
    Expr* left() { return lef; }
    Expr* right() { return ri; }
    any accept(Visitor* v) override {
        return v->visitBiOperation(this);
    }
};

class Cond : public Expr {
    string op_;
    Expr* lef;
    Expr* ri;

public:
    Cond(Expr* l, string op, Expr* r)
        : lef(l), ri(r), op_(op) {
    }

    ~Cond() {
        delete lef;
        if (ri != nullptr) {
            delete ri;
        }
    }

    Expr* left() { return lef; }

    Expr* right() {
        return ri;//может быть nullptr для одиночного условия
    }

    string znak() { return op_; }

    any accept(Visitor* v) override {
        return v->visitCondition(this);
    }
};



class Number : public Expr {
    double val;

public:
    Number(int v) : val(v) {}
    Number(double v) : val(v) {}

    double getVal() { return val; }

    any accept(Visitor* v) override {
        return v->visitNumber(this);
    }
};


class Variable : public Expr {
    string name;

public:
    Variable(string n) : name(n) {}

    string getvar() { return name; }

    any accept(Visitor* v) override {
        return v->visitVariable(this);
    }
};




class Assignment : public Expr {
    Expr* lef;
    Expr* ri;

public:
    Assignment(Expr* l, Expr* r)
        : lef(l), ri(r) {
    }

    ~Assignment() {
        delete lef;
        delete ri;
    }

    Expr* left() { return lef; }
    Expr* right() { return ri; }

    any accept(Visitor* v) override {
        v->visitAssignment(this);
        return {};
    }
};


class Semicol : public Expr {
    Expr* lef;
    Expr* ri;

public:
    Semicol(Expr* l, Expr* r)
        : lef(l), ri(r) {
    }

    ~Semicol() {
        delete lef;
        delete ri;
    }

    Expr* left() { return lef; }
    Expr* right() { return ri; }

    any accept(Visitor* v) override {
        v->visitSemicolon(this);
        return {};
    }
};



class While : public Expr {
    Cond* cond_;
    vector<Expr*> bod;

public:
    While(Cond* c, vector<Expr*> b)
        : cond_(c), bod(b) {
    }

    ~While() {
        delete cond_;
        for (auto x : bod)
            delete x;
    }

    Cond* getCondition() { return cond_; }
    vector<Expr*>& getBody() { return bod; }

    any accept(Visitor* v) override {
        v->visitWhile(this);
        return {};
    }
};


class CalcVis : public Visitor {
    IMap<string, double>* vars;

public:
    CalcVis(IMap<string, double>* m)
        : vars(m) {
    }

    double visitNumber(Number* num) override {
        return num->getVal();
    }

    double visitVariable(Variable* var) override {
        double* val = vars->get(var->getvar());
        if (val == nullptr) {
            throw runtime_error("var" + var->getvar() + "not here");
        }
        return *val;
    }

    void visitAssignment(Assignment* as) override {
        Variable* v = dynamic_cast<Variable*>(as->left());
        if (v == nullptr) {
            throw runtime_error("left side must be var");
        }

        string name = v->getvar();
        double value = any_cast<double>(as->right()->accept(this));

        vars->insert(name, value);
    }

    double visitBiOperation(BiOperation* op) override {
        double l = any_cast<double>(op->left()->accept(this));
        double r = any_cast<double>(op->right()->accept(this));

        switch (op->op()) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/':
            if (r == 0.0) {
                throw runtime_error("why u devide on zero!!");
            }
            return l / r;
        default:
            throw runtime_error("tf is this op");
        }
    }

    void visitWhile(While* wh) override {
        while (true) {
            any condResult = wh->getCondition()->accept(this);
            bool condition = any_cast<bool>(condResult);

            if (!condition) break;

            for (auto stmt : wh->getBody()) {
                stmt->accept(this);
            }
        }
    }

    void visitSemicolon(Semicol* sem) override {
        sem->left()->accept(this);
        sem->right()->accept(this);
    }

    bool visitCondition(Cond* cond) override {
        double l = any_cast<double>(cond->left()->accept(this));

        if (cond->znak().empty()) {
            return l != 0.0;
        }

        double r = any_cast<double>(cond->right()->accept(this));
        string op = cond->znak();

        if (op == "<")  return l < r;
        if (op == ">")  return l > r;
        if (op == "==") return l == r;
        if (op == "<=") return l <= r;
        if (op == ">=") return l >= r;
        if (op == "!=") return l != r;

        throw runtime_error("tf is this comp ");
    }
};

class PrintVis : public Visitor {
public:
    double visitNumber(Number* num) override {
        cout << num->getVal();
        return 0;
    }

    double visitVariable(Variable* var) override {
        cout << var->getvar();
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

    void visitSemicolon(Semicol* sem) override {
        sem->left()->accept(this);
        cout << ";" << endl;
        if (sem->right() != nullptr) {
            sem->right()->accept(this);
        }
    }

    bool visitCondition(Cond* cond) override {
        cond->left()->accept(this);

        if (cond->znak().empty()) {
            return false;
        }

        cout << " " << cond->znak() << " ";
        cond->right()->accept(this);

        return false;
    }

    void visitWhile(While* wh) override {
        cout << "while ";
        wh->getCondition()->accept(this);
        cout << " do" << endl;

        for (auto stmt : wh->getBody()) {
            cout << "  ";
            stmt->accept(this);
            cout << ";" << endl;
        }

        cout << "end";
    }
};