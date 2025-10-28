#include <iostream>
#include <string>
#include <stack>

bool isOpenParenthesis(char c)
{
	return c == '(' || c == '[' || c == '{';
}

char getOpeningParenthesis(char closing)
{
	switch(closing)
	{
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	default:
		throw std::invalid_argument("not a closing parenthesis");
	}
}

bool checkExpression(const std::string& expr)
{
	std::stack<char> s;
	for(char c : expr)
		if(isOpenParenthesis(c))
			s.push(c);
		else
			try {
				if(s.empty() || s.top() != getOpeningParenthesis(c))
					return false;
				else s.pop();
			}
	catch(const std::invalid_argument&)
	{
		return false;
	}
	return s.empty();
}

int main()
{
	std::cout << checkExpression("(([]){}())") << '\n';
	std::cout << checkExpression("([)]") << '\n';
	std::cout << checkExpression(")(") << '\n';
	std::cout << checkExpression("(()") << '\n';
	std::cout << checkExpression("((adf))") << '\n';
	return 0;
}
