#include <iostream>
#include <vector>
#include <cstddef>
#include <queue>
#include <algorithm>
#include <utility>

using pos_t = std::pair<std::size_t, std::size_t>;
template<class T>
using Matrix = std::vector<std::vector<T>>;

std::vector<pos_t> read_pairs(std::size_t n)
{
	std::vector<pos_t> res;
	res.reserve(n);
	while(n--)
	{
		std::size_t row, col;
		std::cin >> row >> col;
		res.push_back(pos_t{row, col}); // res.emplace_back(row, col);
	}
	return res;
}

bool is_healthy(const Matrix<int>& matrix, pos_t pos)
{
	if(matrix.empty()) return false;
	auto [row, col] = pos;
	if(row >= matrix.size() || col >= matrix[0].size())
		return false;
	return matrix[row][col] == -1;
}

unsigned spread_virus(std::size_t rows, std::size_t cols,
					  const std::vector<pos_t>& virus_pos,
					  const std::vector<pos_t>& blocked_pos)
{
	Matrix<int> matrix(rows, std::vector<int>(cols, -1));
	for(auto [row, col] : blocked_pos)
		matrix[row][col] = -2;

	unsigned days = 0;
	std::queue<pos_t> q;
	for(auto [row, col] : virus_pos)
	{
		q.push({row, col});
		matrix[row][col] = days;
	}

	while(!q.empty())
	{
		auto [row, col] = q.front();
		q.pop();

		constexpr std::size_t directions = 4;
		constexpr int dr[] = {-1, 0, 1, 0};
		constexpr int dc[] = {0,  1, 0, -1};

		for(std::size_t i = 0; i < directions; i++)
		{
			pos_t adj{row + dr[i], col + dc[i]};
			if(is_healthy(matrix, adj))
			{
				q.push(adj);
				auto [adj_row, adj_col] = adj;
				matrix[adj_row][adj_col] = matrix[row][col] + 1;
				days = std::max(days, static_cast<unsigned>(matrix[adj_row][adj_col]));
			}
		}
	}
	return days;
}

int main()
{
	std::size_t rows, cols, viruses_cnt;
	std::cin >> rows >> cols >> viruses_cnt;
	std::vector<pos_t> virus_pos = read_pairs(viruses_cnt);
	std::size_t blocked_cnt;
	std::cin >> blocked_cnt;
	std::vector<pos_t> blocked_pos = read_pairs(blocked_cnt);
	std::cout << spread_virus(rows, cols, virus_pos, blocked_pos) << '\n';
	return 0;
}

/*
6 6
2
1 0
3 3
3
0 0
2 2
2 3
*/
