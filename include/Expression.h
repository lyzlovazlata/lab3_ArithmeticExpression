#pragma once
#include <string>
#include "LexAutomat.h"
#include "SyntAutomat.h"
#include "TQueue.h"
#include "Word.h"
#include "TreeExpression.h"
#include <iostream>
using namespace std;

class Expression {

    string in;
    TQueue<Word> infix;
    Tree<Word> postfix;
    int res;

    Expr* buildTree(const Tree<Word>& postfix);

public:
    Expression(string _in);
    Expression(const Expression& expr);
    Expression& operator=(const Expression& expr);
    void run();

    TQueue<Word> getInfix();
    Tree<Word> getPostfix();
    int getRes();
    friend ostream& operator<<(ostream& ostr, Expression exp);

    void deleteExpr(Expr* e);
};