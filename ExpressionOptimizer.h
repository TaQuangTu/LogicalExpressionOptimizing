#ifndef UTILITY
#include"Utility.h"
#define ULTILITY
#endif
using namespace std;
class ExpressionOptimizer
{
private:
	static void backtrack(vector<Expression>&allResult, string&aResult, Expression& oldExpr, vector<char>&literals)
	{
		Expression newExpr(aResult);
		if (newExpr.getCost() <= oldExpr.getCost())
		{
			if (newExpr.equals(oldExpr))
			{
				allResult.push_back(newExpr);
				return;
			}
		}
		for (int i = 0; i < literals.size(); i++)
		{
			if (aResult.size() == 0 && literals[i] == '+') continue;
			//else
			aResult.push_back(literals[i]);
			if (literals[i] == '+') 
			{
				i == -1;   //just a trick to ignore checking every
				continue;  //string that has the last character is +
			}; 				
			if (Expression::isValidStringExpression(aResult))
			{
				backtrack(allResult, aResult, oldExpr, literals);
			}
			aResult.pop_back();
		}
	}
public:
	vector<Expression> getSimpliers(Expression& expr)
	{
		vector<char> literals = Utility::getLiterals(expr);
		literals.push_back('+');
		literals.push_back('\'');

	}
};