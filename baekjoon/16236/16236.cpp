#include <iostream>
#include <vector>
#include <queue>


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
	int m = 0;
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
			else if (arr[i][j] != 0)
			{
				m++;
			}
		}
	}

	int cursize = 2;
	int eatcnt = 0;
	int ans = 0;
	while (true)
	{
		int nx = r, ny = c;
		int range = INT_MAX;
		bool Eaten = false;
		for (int i = 0;i < n;++i)
		{
			for (int j = 0;j < n;++j)
			{

				if (0 != arr[i][j] && arr[i][j] < cursize)
				{
					int curdiff = abs(i - r) + abs(j - c);
					if (curdiff < range)
					{
						nx = i;
						ny = j;
						range = curdiff;
						Eaten = true;

					}
					else if (curdiff == range &&(i < nx || i == nx && j < ny) )
					{
						nx = i;
						ny = j;
						range = curdiff;
						Eaten = true;

					}
				}
			}
		}

		for (int i = 0;i < n;++i)
		{
			for (int j = 0;j < n;++j)
			{
				visited[i][j] = INT_MAX;
			}
		}

		const int n_x[4] = {1,-1,0,0};
		const int n_y[4] = { 0,0,1,-1 };
		if (true == Eaten)
		{
			arr[nx][ny] = 0;

			//bfs
			std::queue<std::pair<int,int>> q;
			q.push(std::make_pair(r, c));
			visited[r][c] = 0;
			while (!q.empty())
			{
				std::pair<int, int> cur = q.front();
				q.pop();
				for (int k = 0;k < 4;++k)
				{
					int nextX = cur.first + n_x[k];
					int nextY = cur.second + n_y[k];
					if (true == in_range(nextX, nextY, n) && visited[nextX][nextY] > visited[cur.first][cur.second]+1 && arr[nextX][nextY]<= cursize)
					{
						q.push(std::make_pair(nextX, nextY));
						visited[nextX][nextY] = visited[cur.first][cur.second] + 1;
					}
				}

			}
			ans += visited[nx][ny];


			r = nx;
			c = ny;
			m--;
			eatcnt++;
			if (eatcnt == cursize)
			{
				cursize++;
				eatcnt = 0;
			}
		}
		else
		{
			break;
		}
	}
	std::cout << ans;
	return 0;
}