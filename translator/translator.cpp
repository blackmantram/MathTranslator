#include "translator.h"
#include <string>

using namespace std;

Translator::Translator(){};

bool Translator::hasExponential(string expression) {
	return expression.find("^") != string::npos;
}

string Translator::translate(string expression) {
	if (expression.empty())
		return "";
	if (hasExponential(expression))
	{
		string delimiter = "^";
		int postition = expression.find(delimiter);
		string base = expression.substr(0, postition);
		string exponent = expression.substr(postition+1, expression.length()-1);
		return base+" a la "+exponent;
	}
	return expression;
};