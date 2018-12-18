#ifndef VECTOR
#include<vector>
#define VECTOR
#endif
#ifndef EXPRESSION
#include"Expression.h"
#define EXPRESSION
#endif
#include<algorithm>
using namespace std;
class Utility
{
public:
	static vector<char> getLiterals(Expression& expr)
	{
		vector<char> literals;
		string str = expr.getString();
		map<char, int> charToInt;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 65 && str[i] <= 90) charToInt[str[i]] = 1;
		}
		for (auto it : charToInt) literals.push_back(it.first);
		return literals;
	}
	static map<char,bool> createMap(vector<char>& literals, vector<bool> values)
	{
		map<char, bool> litAndVal;
		for (int i = 0; i < values.size(); i++)
		{
			litAndVal[literals[i]] = values[i];
		}
		return litAndVal;
	}
	static void backtrack(vector<map<char, bool>>& possibleInput,vector<char>& literals, vector<bool>& aResult, int&n)
	{
		if (aResult.size() == n)
		{
			possibleInput.push_back(createMap(literals,aResult));
			return;
		}
		for (auto it : { false, true })
		{
			aResult.push_back(it);
			backtrack(possibleInput,literals,aResult, n);
			aResult.pop_back();
		}
	}
	static vector<map<char, bool>> getFullInput(vector<char>& literals)
	{
		vector<map<char, bool>> possibleInput;
		int size = literals.size();
		int n = literals.size();
		vector<bool> aResult;
		backtrack(possibleInput, literals, aResult, n);
		return possibleInput;
	}
	static void sortInDescendingSize(vector<Expression>& expressions)
	{
		sort(expressions.begin(), expressions.end(), Expression::compareSize);
	}
	static void showVector(vector<Expression>& expressions)
	{
		for (int i = 0; i < expressions.size();i++)
		cout << expressions[i] << endl;
	}
	static bool contains(string str, string sub)
	{
		if (str.find(sub) != string::npos) {
			return true;
		}
		return false;
	}
	//and more static methods goes here 
};