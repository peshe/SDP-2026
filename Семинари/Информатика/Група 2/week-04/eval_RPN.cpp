#include <iostream>
#include <vector>
#include <stack>

template<class T>
struct RPN_token
{
	bool is_op;
	union
	{
		char op;
		T arg;
	};
};

template<class T>
T do_operation(const T& lhs, const T& rhs, char op)
{
	switch(op)
	{
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	case '*':
		return lhs * rhs;
	case '/':
		return lhs / rhs;
	default:
		throw std::runtime_error("unsupported operation");
	}
}

template<class T>
T eval_RPN(const std::vector<RPN_token<T>>& rpn)
{
	std::stack<T> s;
	for(RPN_token token : rpn)
	{
		if(!token.is_op)
			s.push(token.arg);
		else
		{
			if(s.size() < 2) throw std::runtime_error("invalid expression");
			T rhs = s.top();
			s.pop();
			T lhs = s.top();
			s.pop();
			s.push(do_operation(lhs, rhs, token.op));
		}
	}
	if(s.size() != 1)
		throw std::runtime_error("invalid expression");
	return s.top();
}

int main()
{
	{
		std::vector<RPN_token<int>> expr{{.is_op = false, .arg = 2},
										 {.is_op = false, .arg = 3},
										 {.is_op = false, .arg = 4},
										 {.is_op = true, .op = '*'},
										 {.is_op = true, .op = '+'}};
		std::cout << eval_RPN(expr) << '\n';
	}
	{
		std::vector<RPN_token<int>> expr{{.is_op = false, .arg = 2},
										 {.is_op = false, .arg = 3},
										 {.is_op = true, .op = '+'},
										 {.is_op = false, .arg = 4},
										 {.is_op = true, .op = '*'}};
		std::cout << eval_RPN(expr) << '\n';
	}
	return 0;
}
