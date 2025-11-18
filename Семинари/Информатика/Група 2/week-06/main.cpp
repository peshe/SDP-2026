#include <iostream>

#include "forward_list.hpp"

int main()
{
	forward_list<int> list{5,2,4,1};
	list.insert_after(list.before_begin(), 10);
	list.insert_after(list.before_begin(), 11);

	for(auto it = list.begin(); it != list.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	// 10, 11, 5, 2, 4, 1
	auto it = list.begin();
	++it; ++it; ++it;
	list.erase_after(it);
	list.insert_after(it, 100);

	for(int x : list)
		std::cout << x << ' ';
	std::cout << std::endl;
}
