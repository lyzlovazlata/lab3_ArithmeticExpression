#include <string>
#include <iostream>
#include <locale.h>
#include "antlr4-runtime.h"
#include "PascalLexer.h"
#include "PascalParser.h"
#include "TreeBuilderVis.h"
#include "MyTreeExpr.h"
#include "AVLMap.h"

using namespace antlr4;
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    string input = "a = 5; b = a + 3 * 2; a = 0; while (a<5) do a = a+2; end;";

    ANTLRInputStream inputStream(input);
    PascalLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    PascalParser parser(&tokens);

    auto tree = parser.program();

    TreeBuilderVisitor builder;
    Expr* my_tree = any_cast<Expr*>(builder.visitProgram(tree));

    cout << "TREE: ";
    PrintVisitor printer;
    my_tree->accept(&printer);
    cout << endl;

    cout << "TREE Postfix: ";
    PrintPostfixVisitor printerpostfix;
    my_tree->accept(&printerpostfix);
    cout << endl;

    cout << "Executing:" << endl;

    AVLMap<string, double>* my_map = new AVLMap<string, double>();
    CalcVisitor calculator(my_map);
    my_tree->accept(&calculator);

    cout << *my_map;

    delete my_map;
    return 0;
}