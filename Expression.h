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
	Expression(string newEx)
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
		//check if "this" equals to expr
		return true; //or false
	}
	int getCost()
	{
		//cost = numberOfLiteral + numberOf AND + numberOf OR operators
		return 0; //return cost
	}
	static bool isValidStringExpression(string stringOfExpr)
	{
		//fimiliar to the function "bool isLegalExpression()" above but check for string, not for Expression object
		return false;//or true
	}
	bool isValidExpression()
	{
		//EX: if the string of expression is "AB++C" then return false
		//"AA+BCC+D'G+G" --> return true;
		//"AA+" --> return false
		//"AA+'H"-->return false
		//and some case like that
		return false; //or false
	}
};