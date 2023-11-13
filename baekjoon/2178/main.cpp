#include <iostream>
#include <vector>
#include <climits>

#include <queue>

bool in_range(int x, int y, int n, int m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
	int n, m;
	std::cin >> m >> n;
	std::vector<std::vector<int>> arr;
	std::vector<std::vector<int>> Weight;

	arr.resize(m);
	Weight.resize(m);
	for (int j = 0;j < m;j++)
	{
		for (int i = 0;i < n;i++)
		{
			char tmp;
			std::cin >> tmp;
			arr[j].push_back(tmp-'0');
			Weight[j].push_back(INT_MAX);
		}
	}

	const int nx[4] = { 0,0,-1,1 };
	const int ny[4] = { 1,-1,0,0 };

	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(0, 0));
	Weight[0][0] = 1;

	while (!q.empty())
	{
		std::pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0;i < 4;++i)
		{
			int nextX = cur.first + nx[i];
			int nextY = cur.second + ny[i];
			if (true == in_range(nextX,nextY,n,m) && 1 == arr[nextY][nextX] && Weight[nextY][nextX] > Weight[cur.second][cur.first] + 1)
			{
				Weight[nextY][nextX] = Weight[cur.second][cur.first] + 1;
				q.push(std::make_pair(nextX, nextY));
			}
		}
	}
	std::cout << Weight[m - 1][n - 1];
	
	return 0;

}