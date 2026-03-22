#include "Postfixer.h"

Postfixer::Postfixer() {}

Postfixer::Postfixer(const TQueue<Word> _in) {
	in = _in;
	st = TStack<Word>(in.getSZ());
	tree = TStack<Expr*>(in.getSZ());
}

void Postfixer::run()
{
	while (!in.isEmpty())
	{
		Word w = in.pop();
		pos(w);

	}

	while (!st.isEmpty())
	{
		stackItem = st.pop();
		Expr* r = tree.pop();
		Expr* l = tree.pop();
		tree.push(new BiOperation(stackItem.getValue(), l, r));
	}

	if (tree.isEmpty()) throw "Empty tree";
	root = tree.pop();
}


void Postfixer::operatorWork(Word inItem)
{		
	if (!inItem.isBin())
	{
		tree.push(new Number(0));
	}

	while (!st.isEmpty())
	{
		stackItem = st.top();

		if (priority[char(inItem.getValue())] <= priority[char(stackItem.getValue())])
		{
			st.pop();
			if (tree.isEmpty()) throw "Tree error";
			Expr* r = tree.pop();
			if (tree.isEmpty()) throw "Tree error";
			Expr* l = tree.pop();
			tree.push(new BiOperation(stackItem.getValue(), l, r));
		}
		else
		{
			break;
		}
	}
	if (!inItem.isBin() && st.isEmpty())
	{
		tree.push(new Number(0));
	}

	st.push(inItem);
}


void Postfixer::pos(Word word)
{
	inItem = word;

	if (word.isNum()) tree.push(new Number(inItem.getValue()));

	else if (char(word.getValue()) == '(') st.push(inItem);

	else if (char(word.getValue()) == ')')
	{
		stackItem = st.pop();
		while (char(stackItem.getValue()) != '(')
		{
			Expr* r = tree.pop();
			Expr* l = tree.pop();
			tree.push(new BiOperation(stackItem.getValue(), l, r));
			stackItem = st.pop();
		}
	}

	else
	{
		operatorWork(inItem);
	}
}

Expr* Postfixer::getRoot() {
	return root;
}