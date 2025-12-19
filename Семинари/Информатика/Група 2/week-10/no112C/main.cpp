// https://infos.infosbg.com/contests/NOI/2013

#include <iostream>
#include <queue>
#include <vector>

using Graph = std::vector<std::vector<unsigned>>;

void BFS(const Graph& g, std::vector<unsigned>& components, unsigned start)
{
	std::queue<unsigned> q;
	q.push(start);
	components[start] = start;
	while(!q.empty())
	{
		unsigned current = q.front();
		q.pop();

		for(unsigned adj : g[current])
			if(components[adj] == 0)
			{
				q.push(adj);
				components[adj] = start;
			}
	}
}

Graph readGraph()
{
	unsigned vertices, edges;
	std::cin >> vertices >> edges;
	Graph g(vertices + 1);
	while(edges--)
	{
		unsigned from, to;
		std::cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	return g;
}

std::vector<unsigned> findComponents(const Graph& g)
{
	std::vector<unsigned> components(g.size());
	for(unsigned i = 1; i < g.size(); i++)
		if(components[i] == 0)
			BFS(g, components, i);
	return components;
}

void solveQueries(unsigned cnt, const std::vector<unsigned>& components)
{
	while(cnt--)
	{
		unsigned from, to;
		std::cin >> from >> to;
		std::cout << (components[from] == components[to]);
	}
	std::cout << "\r\n";
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.tie(nullptr);

	Graph g = readGraph();
	unsigned queries;
	std::cin >> queries;
	solveQueries(queries, findComponents(g));
	return 0;
}
