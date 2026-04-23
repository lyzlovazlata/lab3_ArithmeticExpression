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

    string input = "aboba = 20; labuba = 1; while (labuba<5) do aboba = aboba +1; labuba = labuba +1;end;";
    ANTLRInputStream inputStream(input);
    PascalLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    PascalParser parser(&tokens);
    auto tree = parser.program();
    TreeBuilderVisitor builder;
    Expr* my_tree = any_cast<Expr*>(builder.visitProgram(tree));
    cout << "tree ";
    PrintVis printer;
    my_tree->accept(&printer);
    cout << endl;

    cout << "after calcing we have" << endl;

    AVLMap<string, double>* my_map = new AVLMap<string, double>();
    CalcVis calculator(my_map);
    my_tree->accept(&calculator);
    cout << *my_map;
    delete my_map;
    return 0;
}