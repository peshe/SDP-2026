// Problem statement: https://infos.infosbg.com/files/Contests/NOI-2/2017/A/statements/stories.pdf

#include <vector>
#include <deque>
#include <utility>
#include <iostream>

unsigned stories(const std::vector<unsigned long long>& v, unsigned k)
{
	using pair_t = std::pair<unsigned long long, std::size_t>;
	std::deque<pair_t> dq;

	unsigned sum = 0;

	for(std::size_t i = 0; i < v.size(); i++)
	{
		while(!dq.empty() && dq.front().first <= v[i])
			dq.pop_front();
		dq.push_front({v[i], i});
		if(i >= dq.back().second + k)
			dq.pop_back();
		sum += dq.back().first;
	}
	return sum;
}

int main()
{
	std::cout << stories({5, 17, 7, 0, 2, 8, 3}, 3) << '\n';
}
