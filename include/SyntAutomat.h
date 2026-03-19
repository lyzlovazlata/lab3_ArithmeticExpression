#pragma once
#include "TQueue.h"
#include "TStack.h"
#include "Word.h"
#include <map>
#include "Tree.h"
using namespace std;

class SyntAutomat {

    using SFunction = void (SyntAutomat::*)(Word);

    TQueue<Word> in;
    TQueue<int> errs;
    int err_ind;

    int state;
    SFunction** call;
    int** next;

    TStack<int> parOpen;
    TStack<int> parClose;

    map<char, int> priority;
    Tree<Word> postf;
    TStack<Node<Word>*> nums;
    TStack<Node<Word>*> oprs;

    bool canPostfix;

    int nextState(Word c);

    void f0Push(Word word);
    void f1OpErr(Word word);
    void f2OpenParErr(Word word);
    void f3CloseParErr(Word word);
    void f4ValErr(Word word);
    void f5OpUnar(Word word);
    void f6FakeFunc(Word word);

public:

    SyntAutomat();
    ~SyntAutomat();

    SyntAutomat(const TQueue<Word> _in);
    SyntAutomat(const SyntAutomat& _sa);

    SyntAutomat& operator=(const SyntAutomat _sa);

    void run();

    TQueue<Word> getInfix();
    Tree<Word> getPostfix();
    TQueue<int> getErrors();
};