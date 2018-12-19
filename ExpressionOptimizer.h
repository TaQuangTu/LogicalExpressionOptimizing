#include"Expression.h"

using namespace std;
class ExpressionOptimizer
{
private:
	static bool checkValidLoosely(string&str)
	{
		if (str.size() == 0) return true;
		if (Utility::contains(str, "++")) return false;
		if (Utility::contains(str, "+'")) return false;
		if (Utility::contains(str, "''")) return false;
		if (str[0] == '+') return false;
		if (str[0] == '\'') return false;
		return true;
	}
	static void backtrack(vector<Expression>&allResult, string&aResult, Expression& oldExpr, vector<char>&literals, int&size)
	{
		if (aResult.size() > size) return;
		if (Utility::isDuplicateInTerm(aResult)==true) return;
		if (checkValidLoosely(aResult) == false) return;
		
		if (Expression::isValidStringExpression(aResult) == true)
		{
			Expression newExpr(aResult);
			if (newExpr.equals(oldExpr))
			{
				allResult.push_back(newExpr);
				return;
			}
		}

		for (int i = 0; i < literals.size(); i++)
		{
			aResult.push_back(literals[i]);
			backtrack(allResult, aResult, oldExpr, literals, size);
			aResult.pop_back();
		}
	}
public:
	static vector<Expression> getSimpliers(Expression& expr)
	{
		vector<char> literals = Utility::getLiterals(expr.getString());
		vector<Expression> allResults;

		literals.push_back('+');
		literals.push_back('\'');
		int size = expr.getString().size();
		/*for (int i = size; i >= 1; i--)
		{
		string aResult;
		backtrack(allResults, aResult, expr, literals,i);
		}*/
		//Utility::sortInDescendingSize(allResults);
		string aResult;
		int sizeOfOutPut = Utility::getPossibleSize(expr.getString());
		for (int i = 1; i <= sizeOfOutPut; i++)
		{
			cout << "\nCalculating can take a long time!!!\n..."<<(i-1)*100/sizeOfOutPut<<"%...\n";
			backtrack(allResults, aResult, expr, literals, i);
			if (allResults.size() != 0) break;
		}
		return allResults;
	}
};