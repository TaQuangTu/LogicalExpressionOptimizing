#ifndef STRING
#include<string>
#define STRING
#endif
#ifndef MAP
#include<map>
#define MAP
#endif
using namespace std;
class Expression
{
private:
	string strExpression;
public:
	Expression(string newEx="")
	{
		this->strExpression = newEx;
	}
	string getString()
	{
		return this->strExpression;
	}
	bool getValue(map<char, bool>& values)
	{
		//get value of the expression with input from "values", ex:
		//"values" has values['A'] = true,values['B'] = false
		//if strExpression = AB+B' then its value will be true.false+true = true
		return true;//or false
	}
	bool equals(Expression& expr)
	{
		//Incomplete function

		vector<char> literals1 = Utility::getLiterals(*this);
		vector<char> literals2 = Utility::getLiterals(expr);
		vector<map<char, bool>> sets = Utility::getFullInput(literals1);
		for (auto m : sets)
		{
			if (getValue(m) != expr.getValue(m)) return false;
		}
		return true; 
	}
	int getCost()
	{
		int cost = 0;
		for (int i = 0; i < this->strExpression.size(); i++)
		{
			if (strExpression[i] != '\'') cost++;
		}
		return cost;
	}
	static bool isValidStringExpression(string stringOfExpr)
	{
		//add some cases for closely checking
		if (Utility::contains(stringOfExpr, "++")) return false;
		if (Utility::contains(stringOfExpr, "+ +")) return false;
		if (Utility::contains(stringOfExpr, "+'")) return false;
		if (Utility::contains(stringOfExpr, "+ '")) return false;
		if (Utility::contains(stringOfExpr, "''")) return false;
		if (stringOfExpr[0] == '+') return false;
		if (stringOfExpr[0] == '\'') return false;
		if (stringOfExpr[stringOfExpr.size()-1] == '+') return false;
		return true;
	}
	bool isValidExpression()
	{
		return isValidStringExpression(this->strExpression);
	}
	static bool compareSize(Expression a, Expression b)
	{
		return a.getString().size() > b.getString().size();
	}
	friend ostream& operator<<(ostream& out, Expression&b)
	{
		return out << b.getString();
	}
	friend istream& operator>>(istream& iu, Expression&b)
	{
		return in >> b.strExpression;
	}
};
