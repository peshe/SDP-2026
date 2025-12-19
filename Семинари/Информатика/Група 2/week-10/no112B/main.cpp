// https://infos.infosbg.com/contests/NOI/2013

#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

class DSU
{
	std::vector<unsigned> parent, height;
public:
	DSU(unsigned n): height(n, 0)
	{
		parent.reserve(n);
		for(unsigned i = 0; i < n; i++)
			parent[i] = i;
	}

	unsigned find(unsigned x) noexcept
	{
		if(parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	bool join(unsigned x, unsigned y) noexcept
	{
		x = find(x);
		y = find(y);

		if(x == y)
			return false;

		if(height[x] < height[y])
			std::swap(x, y);

		assert(height[x] >= height[y]);
		parent[y] = x;
		if(height[x] == height[y])
			++height[x];
		return true;
	}
};

DSU readGraph()
{
	unsigned vertices, edges;
	std::cin >> vertices >> edges;
	DSU dsu(vertices + 1);
	while(edges--)
	{
		unsigned from, to;
		std::cin >> from >> to;
		dsu.join(from, to);
	}
	return dsu;
}

void solveQueries(unsigned cnt, DSU& dsu)
{
	while(cnt--)
	{
		unsigned type, from, to;
		std::cin >> type >> from >> to;
		switch(type)
		{
		case 1:
			std::cout << (dsu.find(from) == dsu.find(to));
			break;
		case 2:
			dsu.join(from, to);
			break;
		}
	}
	std::cout << "\r\n";
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.tie(nullptr);

	DSU dsu = readGraph();
	unsigned queries;
	std::cin >> queries;
	solveQueries(queries, dsu);
	return 0;
}
