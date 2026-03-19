#include "Expression.h"

Expression::Expression(string _in) : in(_in), res(0) {}
Expression::Expression(const Expression& expr)
{
    in = expr.in;
    infix = expr.infix;
    postfix = expr.postfix;
    res = expr.res;
}
Expression& Expression::operator=(const Expression& expr)
{
    if (this == &expr) return *this;
    in = expr.in;
    infix = expr.infix;
    postfix = expr.postfix;
    res = expr.res;
    return *this;
}

Expr* buildFromNode(const Node<Word>* node)
{
    if (!node) return nullptr;

    Word& val = const_cast<Word&>(node->val);

    if (val.isNum())
    {
        return new Number(val.getValue());
    }
    else
    {
        Expr* l = buildFromNode(node->l);
        Expr* r = buildFromNode(node->r);
        return new BiOperation(char(val.getValue()), l, r);
    }
}

Expr* Expression::buildTree(const Tree<Word>& tree)
{
    const Node<Word>* root = tree.getRoot();
    return buildFromNode(root);
}

void Expression::run()
{
    LexAutomat la(in);
    try
    {
        la.run();
    }
    catch (...)
    {
        cout << "Lex Errors" << endl;
        cout << la.getErrors() << endl;
        throw "Lex Er";
    }

    SyntAutomat sa(la.getLexRes());
    try
    {
        sa.run();
    }
    catch (...)
    {
        cout << "Synt Errors" << endl;
        cout << sa.getErrors() << endl;
        throw "Synt Er";
    }

    infix = sa.getInfix();
    postfix = sa.getPostfix();
    Expr* root = buildTree(postfix);

    CalcVisitor calculator;

    res = root->accept(&calculator);

    deleteExpr(root);
}

TQueue<Word> Expression::getInfix()
{
    return infix;
}
Tree<Word> Expression::getPostfix()
{
    return postfix;
}
int Expression::getRes()
{
    return res;
}

void Expression::deleteExpr(Expr* e) {
    if (!e) return;
    BiOperation* bop = dynamic_cast<BiOperation*>(e);
    if (bop) {
        deleteExpr(bop->left());
        deleteExpr(bop->right());
        delete bop;
        return;
    }
    Number* num = dynamic_cast<Number*>(e);
    if (num) {
        delete num;
        return;
    }
}

ostream& operator<<(ostream& ostr, Expression exp)
{
    PrintVisitor print;
    Expr* root = exp.buildTree(exp.postfix);
    root->accept(&print);
    exp.deleteExpr(root);
    return ostr;
}