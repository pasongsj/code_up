#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> answer;


bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

//void bfs(int x, int y)
//{
//	const int nx[4] = {0,0,1,-1};
//	const int ny[4] = {1,-1,0,0};
//	for (int i = 0; i < 4;++i)
//	{
//		int nextX = x + nx[i];
//		int nextY = y + ny[i];
//		if (
//			true == in_range(nextX, nextY, static_cast<int>(arr.size()), static_cast<int>(arr[x].size())) 
//			&& 1 ==  arr[nextX][nextY]
//			&& (-1 == answer[nextX][nextY] || -1 != answer[nextX][nextY] && answer[nextX][nextY] > answer[x][y] + 1)
//			)
//		{
//			answer[nextX][nextY] = answer[x][y] + 1;
//			bfs(nextX, nextY);
//		}
//	}
//}


int main()
{
	int n, m;
	std::cin >> n >> m;
	arr.resize(n);
	answer.resize(n);
	int sx = -1,sy = -1;

	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(m);
		answer[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> arr[i][j];
			if (2 == arr[i][j])
			{
				sx = i;
				sy = j;
			}
			if (1 == arr[i][j])
			{
				answer[i][j] = -1;
			}
		}
	}
	

	const int nx[4] = { 0,0,1,-1 };
	const int ny[4] = { 1,-1,0,0 };

	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(sx, sy));
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
				1 == arr[nextX][nextY] &&
				(-1 == answer[nextX][nextY] || ( - 1 != answer[nextX][nextY] && answer[nextX][nextY] > answer[cx][cy] + 1))
				)
			{
				answer[nextX][nextY] = answer[cx][cy] + 1;
				q.push(std::make_pair(nextX, nextY));
			}
		}
	}
	
	//bfs(cx, cy);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cout << answer[i][j]<<' ';
		}
		std::cout << '\n';
	}

	return 0;
}