#include <iostream>
#include <vector>
#include <queue>
#include <climits>

bool in_range(int x, int y, int n)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> arr;
	std::vector<std::vector<int>> visited;
	arr.resize(n);
	visited.resize(n);
	int r = 0, c = 0;
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(n);
		visited[i].resize(n);
		for (int j = 0;j < n;++j)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				r = i;
				c = j;
				arr[i][j] = 0;
			}

		}
	}

	int cursize = 2;
	int eatcnt = 0;
	int ans = 0;

	const int nx[4] = { 1,-1,0,0 };
	const int ny[4] = { 0,0,1,-1 };
	while (true)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				visited[i][j] = INT_MAX;
			}
		}

		std::queue<std::pair<int, int>> q;
		int range = INT_MAX;
		std::pair<int, int> dest = std::make_pair(-1,-1);
		q.push(std::make_pair(r, c));
		visited[r][c] = 0;
		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			if (0 !=arr[cx][cy] && cursize>arr[cx][cy])
			{
				if (visited[cx][cy] < range)
				{
					dest = std::make_pair(cx, cy);
					range = visited[cx][cy];
				}
				else if (visited[cx][cy] == range && (cx < dest.first || cx == dest.first && cy < dest.second))
				{
					dest = std::make_pair(cx, cy);
					range = visited[cx][cy];
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				int nextX = cx + nx[i];
				int nextY = cy + ny[i];
				if (true == in_range(nextX, nextY, n) && arr[nextX][nextY] <= cursize && visited[nextX][nextY] > visited[cx][cy]+1)
				{
					visited[nextX][nextY] = visited[cx][cy] + 1;
					q.push(std::make_pair(nextX, nextY));
				}
			}
			
		}
		if (dest.first == -1)
		{
			break;
		}
		r = dest.first;
		c = dest.second;
		arr[r][c] = 0;
		ans += visited[r][c];
		eatcnt++;
		if (eatcnt>=cursize)
		{
			cursize++;
			eatcnt = 0;
		}
	}

	std::cout << ans;
	return 0;
}