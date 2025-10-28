#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreater(const std::vector<int>& v)
{
	std::vector<int> res(v.size(), -1);
	std::stack<int> s;

	for(std::size_t i = 0; i < v.size(); i++)
	{
		while(!s.empty() && v[s.top()] < v[i])
		{
			res[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	return res;
}

template<class R>
std::ostream& printRange(std::ostream& os, const R& r)
{
	for(const auto& elem : r)
		os << elem << ' ';
	return os << '\n';
}

int main()
{
	printRange(std::cout, nextGreater({2, 7, 3, 5, 4, 6, 8}));
	printRange(std::cout, nextGreater({8, 3, 1, 0}));
	return 0;
}
