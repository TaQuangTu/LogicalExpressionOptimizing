#include "ExpressionOptimizer.h"
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		cout << "Type Logical Expression: ";
		Expression expr;
		cin >> expr;
		vector<Expression> optimizeds = ExpressionOptimizer::getSimpliers(Expression(expr));
		Utility::showVector(optimizeds);
	}
	return 0;
}