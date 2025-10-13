#include <iostream>

#include "vector.hpp"

int main()
{
	Vector<int> v;

	for(int i = 0; i < 50; i++)
		v.push_back(i);

	for(int i = 0; i < 50; i++)
		std::cout << v[i] << ' ';
	std::cout << '\n';

	return 0;
}
