#include "ExpressionOptimizer.h"
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		string str;
		cout << "Type Logical Expression: ";
		getline(cin, str);
		Expression expr(str);

		vector<Expression> optimizeds = ExpressionOptimizer::getSimpliers(expr);
        
		for (int i = 0; i < optimizeds.size(); i++)
		{
			cout << optimizeds[i]<< endl;
		}
	}
	return 0;
}
