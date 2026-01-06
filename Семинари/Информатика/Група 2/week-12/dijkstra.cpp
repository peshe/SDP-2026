#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using VertexWithWeight = std::pair<unsigned, unsigned>;
using VertexWithDistance = std::pair<unsigned, unsigned>;
using Graph = std::vector<std::vector<VertexWithWeight>>;

Graph readGraph(std::size_t v, std::size_t e)
{
	Graph g(v);
	while(e--)
	{
		unsigned from, to, w;
		std::cin >> from >> to >> w;
		g[from].emplace_back(to, w);
		g[to].emplace_back(from, w);
	}
	return g;
}

std::pair<std::vector<unsigned>, std::vector<unsigned>> dijkstra(unsigned init, const Graph& g)
{
	std::vector<unsigned> dist(g.size(), std::numeric_limits<unsigned>::max()), prev(g.size(), -1);
	std::vector<bool> visited(g.size(), false);
	auto cmp_dist = [](const VertexWithDistance& lhs, const VertexWithDistance& rhs) noexcept -> bool
		{
			return lhs.second > rhs.second;
		};

	std::priority_queue<VertexWithDistance, std::vector<VertexWithDistance>, decltype(cmp_dist)> pr;
	dist[init] = 0;
	pr.emplace(init, dist[init]);
	while(!pr.empty())
	{
		auto [curr, _] = pr.top();
		pr.pop();
		if(visited[curr]) continue;
		visited[curr] = true;
		for(auto [to, w] : g[curr])
			if(dist[to] > dist[curr] + w)
			{
				dist[to] = dist[curr] + w;
				pr.emplace(to, dist[to]);
				prev[to] = curr;
			}
	}
	return {std::move(dist), std::move(prev)};
}

int main()
{
	std::size_t v, e;
	std::cin >> v >> e;
	Graph g = readGraph(v, e);
	auto [dist, prev] = dijkstra(0, g);
	for(std::size_t i = 0; i < dist.size(); i++)
		std::cout << "dist to " << i << " = " << dist[i] << '\n';
	for(std::size_t i = 0; i < prev.size(); i++)
		std::cout << "prev of " << i << " = " << prev[i] << '\n';
}

/*
6 9
0 1 7
1 3 15
0 2 9
2 1 10
0 5 14
2 5 2
2 3 11
5 4 9
4 3 6
*/