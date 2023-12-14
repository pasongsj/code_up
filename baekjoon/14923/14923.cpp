#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

std::vector<std::vector<int>> graph;
const int nx[4] = { 0,0,1,-1 };
const int ny[4] = { 1,-1,0,0 };
int n, m;

bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int getpoint(std::pair<int, int> _brokenpoint, std::pair<int,int> dest, std::vector<std::vector<int>> dpgraph)
{
	int cx, cy;
	std::tie(cx, cy) = _brokenpoint;
	for (int i = 0; i < 4; ++i)
	{
		int nextX = cx + nx[i];
		int nextY = cy + ny[i];
		if (true == in_range(nextX, nextY, n, m) &&
			dpgraph[nextX][nextY] + 1 < dpgraph[cx][cy] &&
			INT_MAX != dpgraph[nextX][nextY])
		{
			dpgraph[cx][cy] = dpgraph[nextX][nextY] + 1;
		}
	}
	if (INT_MAX == dpgraph[cx][cy])
	{
		return dpgraph[dest.first][dest.second];
	}
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(cx, cy));
	while (!q.empty())
	{
		std::tie(cx, cy) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextX = cx + nx[i];
			int nextY = cy + ny[i];

			if (
				true == in_range(nextX, nextY, n, m) &&
				0 == graph[nextX][nextY] &&
				dpgraph[nextX][nextY] > dpgraph[cx][cy] + 1
				)
			{
				dpgraph[nextX][nextY] = dpgraph[cx][cy] + 1;
				q.push(std::make_pair(nextX, nextY));
			}
		}
	}
	return dpgraph[dest.first][dest.second];
}

int main()
{
	std::cin >> n >> m;
	int hx, hy;
	std::cin >> hx >> hy;
	hx--, hy--;
	int ex, ey;
	std::cin >> ex >> ey;
	ex--, ey--;
	std::vector<std::vector<int>> dpgraph;
	graph.resize(n);
	dpgraph.resize(n);

	std::vector<std::pair<int, int>> walls;

	for (int i = 0; i < n; ++i)
	{
		graph[i].resize(m);
		dpgraph[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> graph[i][j];
			dpgraph[i][j] = INT_MAX;
			if (1 == graph[i][j])
			{
				walls.push_back(std::make_pair(i, j));
			}
		}
	}




	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(hx, hy));
	dpgraph[hx][hy] = 0;
	while (!q.empty())
	{
		int cx, cy;
		std::tie(cx, cy) = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextX = cx + nx[i];
			int nextY = cy + ny[i];

			if (
				true == in_range(nextX, nextY, n, m) &&
				0 == graph[nextX][nextY] &&
				dpgraph[nextX][nextY] > dpgraph[cx][cy] + 1
				)
			{
				dpgraph[nextX][nextY] = dpgraph[cx][cy] + 1;
				q.push(std::make_pair(nextX, nextY));
			}
		}
	}

	int answer = dpgraph[ex][ey];
	for (int i = 0; i < walls.size(); ++i)
	{
		int res = getpoint(walls[i], std::make_pair(ex, ey), dpgraph);
		answer = answer > res ? res : answer;
	}

	std::cout << answer;
	return 0;
}