#include <iostream>
#include <cstddef>

#include "vector.hpp"
#include "alg.hpp"
#include "back_insert_iterator.hpp"

template<class T>
Vector<T> read(std::size_t n)
{
	Vector<T> res;
	while(n--)
	{
		T tmp;
		std::cin >> tmp;
		res.push_back(std::move(tmp));
	}

	return res;
}

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	std::size_t n;
	std::cin >> n;
	Vector<int> v1 = read<int>(n);

	std::cin >> n;
	Vector<int> v2 = read<int>(n);

	Vector<int> v3;

	merge(v1.begin(), v1.end(), v2.rbegin(), v2.rend(), Back_insert_iterator(v3), cmp);

	for(std::size_t i = 0; i < v3.size(); i++)
		std::cout << v3[i] << ' ';
	std::cout << '\n';

	for(auto it = v3.begin(); it != v3.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	for(int x : v3)
		std::cout << x << ' ';
	std::cout << '\n';

	return 0;
}

/*
6
-4 2 3 5 18 100
6
10 8 2 2 0 -1
*/
