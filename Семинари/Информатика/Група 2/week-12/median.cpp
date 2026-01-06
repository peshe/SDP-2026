#include <iostream>
#include <queue>
#include <utility>

bool less(unsigned a, unsigned b) { return a < b; }
bool greater(unsigned a, unsigned b) { return a > b; }

class Median
{
	using PQ = std::priority_queue<unsigned, std::vector<unsigned>, bool(*)(unsigned, unsigned)>;
	PQ L, H;
	double median;

	std::size_t size() const noexcept
	{
		return L.size() + H.size();
	}
public:
	Median(): L(&less), H(&greater), median(0) {}

	void add(unsigned val)
	{
		if(size() == 0)
		{
			L.push(val);
			median = val;
			return;
		}

		PQ *L_ptr = &L, *H_ptr = &H;
		if(val > median)
			std::swap(L_ptr, H_ptr);

		L_ptr->push(val);

		if(size() % 2)
			median = L_ptr->top();
		else
		{
			while(L_ptr->size() != H_ptr->size())
			{
				H_ptr->push(L_ptr->top());
				L_ptr->pop();
			}
			median = (L.top() + H.top()) / 2.0;
		}
	}
	double get() const noexcept
	{
		return median;
	}
};

int main()
{
	Median m;
	std::size_t n;
	std::cin >> n;
	while(n--)
	{
		unsigned val;
		std::cin >> val;
		m.add(val);
		std::cout << "median = " << m.get() << '\n';
	}
}
