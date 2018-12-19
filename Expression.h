#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
vector<vector<bool>> possibleInput[11];
class Expression;
class Utility
{
public:
	static bool isDuplicateInTerm(string&str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			bool metPlus = false;
			char temp = str[i];
			for (int j = i + 1; j < str.size(); j++)
			{
				if (str[j] == '+') metPlus = true;
				if (metPlus == false && temp == str[j]) return true;
			}
		}
		return false;
	}
	/*static bool isDuplicate(string&str)
	{
		int size = str.size() - 1;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == str[i + 1]) return true;
		}
		return false;
	}*/
	static int getPossibleSize(string& str)
	{
		map<char, int> appeared;
		int sum = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' '&&str[i] != '\'')
			{
				sum++;
			}
		}
		return sum;
	}
	static vector<char> getLiterals(string str)
	{
		vector<char> literals;
		map<char, int> charToInt;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 65 && str[i] <= 90) charToInt[str[i]] = 1;
		}
		for (auto it : charToInt) literals.push_back(it.first);
		return literals;
	}
	static void createPossibleInput()
	{	
		for (int i = 1; i <= 10; i++)
		{
			if (possibleInput[i].size() == 0)
			{
				vector<bool> temp;
				backtrack1(possibleInput[i],temp, i);
			}	
		}
	}
	static map<char, bool> createMap(vector<char>& literals, vector<bool>& values)
	{
		map<char, bool> litAndVal;
		for (int i = 0; i < values.size(); i++)
		{
			litAndVal[literals[i]] = values[i];
		}
		return litAndVal;
	}
	static void backtrack1(vector<vector<bool>>& allResults,  vector<bool>& aResult, int n)
	{
		if (aResult.size() == n)
		{
			allResults.push_back(aResult);
			return;
		}
		for (auto it : { false, true })
		{
			aResult.push_back(it);
			backtrack1(allResults,aResult, n);
			aResult.pop_back();
		}
	}
	static vector<map<char, bool>> getFullInput(vector<char>& literals)
	{
		vector<map<char, bool>> allInput;
		createPossibleInput();
		int size = literals.size();
		for (int i = 0; i < possibleInput[size].size(); i++)
		{
			allInput.push_back(createMap(literals,possibleInput[size][i]));
		}
		return allInput;
	}
	/*static void sortInDescendingSize(vector<Expression>& expressions)
	{
		sort(expressions.begin(), expressions.end(), Expression::compareSize);
	}*/
	static void showVector(vector<string>& expressions)
	{
		for (int i = 0; i < expressions.size(); i++)
			cout << expressions[i] << endl;
	}
	static bool contains(string str, string sub)
	{
		if (str.find(sub) != string::npos) {
			return true;
		}
		return false;
	}
	static bool getBooleanValue(vector<bool>& values)
	{
		if (find(values.begin(), values.end(), false) != values.end()) return false;
		return true;
	}
	//and more static methods goes here 
};
class Expression
{
private:
	string strExpression;
public:
	Expression(string newEx="")
	{
		this->strExpression = newEx;
	}
	string& getString()
	{
		return this->strExpression;
	}
	bool getValue(map<char, bool>& values)
	{
		//A+BC + D'C + A'
		vector<vector<bool>> allTermValues;
		int i = 0;
		while (i<strExpression.size())
		{
			vector<bool> term;
			while (i < strExpression.size() && strExpression[i]!= '+')
			{
				if (strExpression[i] == ' ')
				{
					i++;
					continue;
				} 
				if (strExpression[i] == '\'')
				{
					if (term.size()>0)
					term[term.size() - 1] = !term[term.size() - 1];
				}
				else term.push_back(values[strExpression[i]]);
				i++;
			}
			allTermValues.push_back(term);
			i++;
		}
		bool result = false;
		for (int i = 0; i < allTermValues.size();i++)
		{
			result = result || Utility::getBooleanValue(allTermValues[i]);
		}
		return result;
	}
	bool equals(Expression& expr)
	{
		//Incomplete function
		vector<char> literals2 = Utility::getLiterals(expr.getString());
		vector<map<char, bool>> sets = Utility::getFullInput(literals2);
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
			if (strExpression[i] != '\''&&strExpression[i] != ' ') cost++;
		}
		return cost;
	}
	static bool isValidStringExpression(string stringOfExpr)
	{
		//add some cases for closely checking
		if (stringOfExpr.size() == 0) return false;
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
	friend istream& operator>>(istream& in, Expression&b)
	{
		return in >> b.strExpression;
	}
};
