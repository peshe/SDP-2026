#include <iostream>
#include <cstddef>
#include <set>
#include <utility>
#include <iterator>

struct Interval
{
	long long L, R;  // [L, R]

	bool operator<(const Interval& rhs) const noexcept
	{
		return L < rhs.L;
	}

	friend std::ostream& operator<<(std::ostream& os, const Interval& rhs)
	{
		return os << '[' << rhs.L << ", " << rhs.R << ']';
	}
};

bool addInterval(std::set<Interval>& intervals, long long val)
{
	std::set<Interval>::iterator next = intervals.upper_bound({val, 0});

	if(next != intervals.begin())
	{
		auto prev = std::prev(next);
		if(prev->L <= val && val <= prev->R)
			return false;

		if(prev->R == val - 1)
		{
			auto nh = intervals.extract(prev);
			if(next != intervals.end() && next->L == val + 1)
			{
				nh.value().R = next->R;
				intervals.erase(next);
			}
			else
				nh.value().R = val;
			intervals.insert(std::move(nh));
			return true;
		}
	}

	if(next != intervals.end() && next->L == val + 1)
	{
		auto nh = intervals.extract(next);
		nh.value().L = val;
		intervals.insert(std::move(nh));
		return true;
	}

	intervals.insert({val, val});
	return true;
}

bool allPointsPresent(const std::set<Interval>& intervals, Interval question)
{
	std::set<Interval>::iterator next = intervals.upper_bound(question);
	if(next == intervals.begin())
		return false;
	auto prev = std::prev(next);
	return prev->L <= question.L && question.R <= prev->R;
}

void debugPrint(const std::set<Interval>& intervals)
{
	for(auto interval : intervals)
		std::cerr << interval << '\n';
}

int main()
{
	std::size_t queries;
	std::cin >> queries;
	std::set<Interval> intervals;
	while(queries)
	{
		char type;
		std::cin >> type;
		switch(type)
		{
		case '+':
		{
			long long val;
			std::cin >> val;
			if(!addInterval(intervals, val))
				std::cout << val << " is already present\n";
			break;
		}
		case '?':
			long long L, R;
			std::cin >> L >> R;
			std::cout << allPointsPresent(intervals, {L, R}) << '\n';
			break;
		}
		debugPrint(intervals);
	}
	std::cout << '\n';
}