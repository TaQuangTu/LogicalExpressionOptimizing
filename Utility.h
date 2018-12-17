#ifndef STRING
#include<string>
#define STRING
#endif
#ifndef MAP
#include<map>
#define MAP
#endif
#ifndef VECTOR
#include<vector>
#define VECTOR
#endif
#ifndef EXPRESSION
#include"Expression.h"
#define EXPRESSION
#endif

using namespace std;
class Utility
{
public:
	static vector<char> getLiterals(Expression& expr)
	{
		vector<char> literals;
		//return vector of literals that expr.getString() contains
		//Example: expr.getString() = "AB+C'D" then literals = {'A','B','C','D'};
		return literals;
	}
	static vector<map<char, bool>> getFullInput(vector<char>& literals)
	{
		vector<map<char, bool>> possibleInput;
		int size = literals.size();

		//example:
		//literals = {'B','C,'D'} then possibleInput will consist of
		// map<char,bool> m1 = {'B'->0,'C'->0,'D'->0}
		// map<char,bool> m2 = {'B'->0,'C'->0,'D'->1}
		// map<char,bool> m3 = {'B'->0,'C'->1,'D'->0}
		// map<char,bool> m4 = {'B'->0,'C'->1,'D'->1}
		// map<char,bool> m5 = {'B'->1,'C'->0,'D'->0}
		// map<char,bool> m6 = {'B'->1,'C'->0,'D'->1}
		// map<char,bool> m7 = {'B'->1,'C'->1,'D'->0}
		// map<char,bool> m8 = {'B'->1,'C'->1,'D'->1}
		return possibleInput;
	}
	//and more static methods goes here 
};