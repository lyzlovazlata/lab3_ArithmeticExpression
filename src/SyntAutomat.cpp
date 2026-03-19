#include "SyntAutomat.h"

int SyntAutomat::nextState(Word c)
{
    if (c.isNum())
        return 1;
    else if ((char)c.getValue() == '(')
        return 0;
    else if ((char)c.getValue() == ')')
        return 2;
    else
        return 3;
}

void SyntAutomat::f0Push(Word word)
{
    Node<Word>* node = new Node<Word>(word);

    if (word.isNum())
    {
        err_ind += word.getLen();
        if (canPostfix)
            nums.push(node);
        else
            delete node;
    }
    else if (char(word.getValue()) == '(')
    {
        oprs.push(node);
    }
    else if (char(word.getValue()) == ')')
    {
        while (!oprs.isEmpty() && char(oprs.top()->val.getValue()) != '(')
        {
            Node<Word>* op = oprs.pop();
            Node<Word>* first = nums.pop();
            Node<Word>* second = nums.pop();
            op->l = second;
            op->r = first;
            nums.push(op);
        }
        if (!oprs.isEmpty() && char(oprs.top()->val.getValue()) == '(')
        {
            Node<Word>* par = oprs.pop();
            delete par;
        }
        delete node;
    }
    else
    {
        if (canPostfix)
        {
            if (!word.isBin())
            {
                Word zeroHelper;
                zeroHelper.getLen() = 1;
                zeroHelper.isNum() = true;
                zeroHelper.isBin() = false;
                zeroHelper.getValue() = 0;

                Node<Word>* zer = new Node<Word>(zeroHelper);
                nums.push(zer);
            }

            while (!oprs.isEmpty() && priority[char(word.getValue())] <= priority[char(oprs.top()->val.getValue())])
            {
                Node<Word>* op = oprs.pop();
                Node<Word>* first = nums.pop();
                Node<Word>* second = nums.pop();
                op->l = second;
                op->r = first;
                nums.push(op);
            }

            oprs.push(node);
        }
        else
        {
            delete node;
        }
    }
}

void SyntAutomat::f1OpErr(Word word)
{
    errs.push(err_ind);
    err_ind++;
    if (canPostfix)
        canPostfix = false;
}
void SyntAutomat::f2OpenParErr(Word word)
{
    parOpen.push(err_ind);
    errs.push(err_ind);
    err_ind++;
    if (canPostfix)
        canPostfix = false;
    return;
}
void SyntAutomat::f3CloseParErr(Word word)
{
    try
    {
        parOpen.pop();
    }
    catch (...)
    {
        parClose.push(err_ind);
    }
    errs.push(err_ind);
    err_ind++;
    if (canPostfix)
        canPostfix = false;
}
void SyntAutomat::f4ValErr(Word word)
{
    errs.push(err_ind);
    err_ind += word.getLen();
    if (canPostfix)
        canPostfix = false;
}
void SyntAutomat::f5OpUnar(Word word)
{
    if (char(word.getValue()) == '+' || char(word.getValue()) == '-')
    {
        word.isBin() = false;
        err_ind++;
        f0Push(word);
    }
    else
        f1OpErr(word);
}
void SyntAutomat::f6FakeFunc(Word word)
{
    return;
}

SyntAutomat::SyntAutomat()
    : in(), errs(1), err_ind(0), state(0),
    parOpen(1), parClose(1),
    priority({ {'+',1},{'-',1},{'*',2},{'/',2},{'(',0} }),
    postf(), nums(1), oprs(1), canPostfix(true)
{
    call = new SFunction * [4];
    next = new int* [4];
    for (size_t i = 0; i < 4; i++)
    {
        call[i] = new SFunction[4];
        next[i] = new int[4];
    }

    next[0][0] = 0; next[0][1] = 1; next[0][2] = 2; next[0][3] = 3;
    next[1][0] = 0; next[1][1] = 1; next[1][2] = 2; next[1][3] = 3;
    next[2][0] = 0; next[2][1] = 1; next[2][2] = 2; next[2][3] = 3;
    next[3][0] = 0; next[3][1] = 1; next[3][2] = 2; next[3][3] = 3;

    call[0][0] = &SyntAutomat::f0Push;
    call[0][1] = &SyntAutomat::f0Push;
    call[0][2] = &SyntAutomat::f3CloseParErr;
    call[0][3] = &SyntAutomat::f5OpUnar;

    call[1][0] = &SyntAutomat::f2OpenParErr;
    call[1][1] = &SyntAutomat::f6FakeFunc;
    call[1][2] = &SyntAutomat::f0Push;
    call[1][3] = &SyntAutomat::f0Push;

    call[2][0] = &SyntAutomat::f2OpenParErr;
    call[2][1] = &SyntAutomat::f4ValErr;
    call[2][2] = &SyntAutomat::f0Push;
    call[2][3] = &SyntAutomat::f0Push;

    call[3][0] = &SyntAutomat::f0Push;
    call[3][1] = &SyntAutomat::f0Push;
    call[3][2] = &SyntAutomat::f3CloseParErr;
    call[3][3] = &SyntAutomat::f1OpErr;
}

SyntAutomat::~SyntAutomat()
{
    for (size_t i = 0; i < 4; i++)
    {
        delete[] call[i];
        delete[] next[i];
    }
    delete[] call;
    delete[] next;

    while (!nums.isEmpty()) delete nums.pop();
    while (!oprs.isEmpty()) { Node<Word>* n = oprs.pop(); delete n; }
}

SyntAutomat::SyntAutomat(const TQueue<Word> _in)
    : in(_in),
    errs(in.getSZ()),
    state(0),
    parOpen(in.getSZ()),
    parClose(in.getSZ()),
    priority({ {'+',1},{'-',1},{'*',2},{'/',2},{'(',0} }),
    postf(),
    nums(in.getSZ()),
    oprs(in.getSZ()),
    canPostfix(true),
    err_ind(0)
{
    call = new SFunction * [4];
    next = new int* [4];
    for (size_t i = 0; i < 4; i++)
    {
        call[i] = new SFunction[4];
        next[i] = new int[4];
    }

    next[0][0] = 0; next[0][1] = 1; next[0][2] = 2; next[0][3] = 3;
    next[1][0] = 0; next[1][1] = 1; next[1][2] = 2; next[1][3] = 3;
    next[2][0] = 0; next[2][1] = 1; next[2][2] = 2; next[2][3] = 3;
    next[3][0] = 0; next[3][1] = 1; next[3][2] = 2; next[3][3] = 3;

    call[0][0] = &SyntAutomat::f0Push;
    call[0][1] = &SyntAutomat::f0Push;
    call[0][2] = &SyntAutomat::f3CloseParErr;
    call[0][3] = &SyntAutomat::f5OpUnar;

    call[1][0] = &SyntAutomat::f2OpenParErr;
    call[1][1] = &SyntAutomat::f6FakeFunc;
    call[1][2] = &SyntAutomat::f0Push;
    call[1][3] = &SyntAutomat::f0Push;

    call[2][0] = &SyntAutomat::f2OpenParErr;
    call[2][1] = &SyntAutomat::f4ValErr;
    call[2][2] = &SyntAutomat::f0Push;
    call[2][3] = &SyntAutomat::f0Push;

    call[3][0] = &SyntAutomat::f0Push;
    call[3][1] = &SyntAutomat::f0Push;
    call[3][2] = &SyntAutomat::f3CloseParErr;
    call[3][3] = &SyntAutomat::f1OpErr;
}

SyntAutomat::SyntAutomat(const SyntAutomat& _sa)
{
    in = _sa.in;
    errs = _sa.errs;
    state = _sa.state;
    call = new SFunction * [4];
    next = new int* [4];
    for (size_t i = 0; i < 4; i++)
    {
        call[i] = new SFunction[4];
        next[i] = new int[4];
        for (size_t j = 0; j < 4; j++)
        {
            call[i][j] = _sa.call[i][j];
            next[i][j] = _sa.next[i][j];
        }
    }
    parOpen = _sa.parOpen;
    parClose = _sa.parClose;

    err_ind = _sa.err_ind;
    priority = _sa.priority;

    postf = _sa.postf;
    nums = _sa.nums;
    oprs = _sa.oprs;

    canPostfix = _sa.canPostfix;
}

SyntAutomat& SyntAutomat::operator=(const SyntAutomat _sa)
{
    if (this == &_sa) return *this;
    in = _sa.in;
    errs = _sa.errs;
    state = _sa.state;
    for (size_t i = 0; i < 4; i++)
    {
        delete[] call[i];
        delete[] next[i];
    }
    delete[] call;
    delete[] next;

    call = new SFunction * [4];
    next = new int* [4];
    for (size_t i = 0; i < 4; i++)
    {
        call[i] = new SFunction[4];
        next[i] = new int[4];
        for (size_t j = 0; j < 4; j++)
        {
            call[i][j] = _sa.call[i][j];
            next[i][j] = _sa.next[i][j];
        }
    }
    parOpen = _sa.parOpen;
    parClose = _sa.parClose;

    err_ind = _sa.err_ind;
    priority = _sa.priority;

    postf = _sa.postf;
    nums = _sa.nums;
    oprs = _sa.oprs;

    canPostfix = _sa.canPostfix;

    return *this;
}

void SyntAutomat::run()
{
    while (!in.isEmpty())
    {
        Word w = in.pop();
        (this->*call[state][nextState(w)])(w);
        state = next[state][nextState(w)];
    }

    while (!parOpen.isEmpty())
    {
        errs.push(parOpen.pop());
        if (canPostfix)
            canPostfix = false;
    }

    while (!parClose.isEmpty())
    {
        errs.push(parClose.pop());
        if (canPostfix)
            canPostfix = false;
    }

    if (state == 3 || state == 0)
    {
        errs.push(--err_ind);
        if (canPostfix)
            canPostfix = false;
    }

    if (!errs.isEmpty())
    {
        throw - 2;
    }

    if (canPostfix)
    {
        while (!oprs.isEmpty())
        {
            Node<Word>* op = oprs.pop();
            if (char(op->val.getValue()) == '(')
            {
                delete op;
                continue;
            }
            Node<Word>* first = nums.pop();
            Node<Word>* second = nums.pop();
            op->l = second;
            op->r = first;
            nums.push(op);
        }

        if (!nums.isEmpty())
        {
            Node<Word>* root = nums.pop();
            postf.setRootNode(root);
        }
    }
}

TQueue<Word> SyntAutomat::getInfix()
{
    return in;
}

Tree<Word> SyntAutomat::getPostfix()
{
    return postf;
}

TQueue<int> SyntAutomat::getErrors()
{
    return errs;
}