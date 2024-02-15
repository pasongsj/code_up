#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
std::vector<std::vector<char>> arr;

class Info
{
public:
	Info(int _x, int _y)
		:x(_x), y(_y),cnty(0),cnts(0)
	{
	}
	Info(int _x, int _y,int _cy,int _cs)
		:x(_x), y(_y), cnty(_cy), cnts(_cs)
	{
	}
	int x = -1;
	int y = -1;
	int cnty = 0;
	int cnts = 0;
};

bool in_range(int x, int y)
{
	return  0 <= x && x < 5 && 0 <= y && y < 5;
}

int  bfs(int x, int y)
{
	std::vector<std::vector<int>> is_visited(5, std::vector<int>(5, 0));

	if (x == 1 && y == 0)
	{
		int a = 0;
	}
	int ans = 0;
	int cnty = 0;
	int cnts = 0;
	std::queue<Info> q;
	Info cur = { x,y,0,0 };
	if (arr[x][y] == 'Y')
	{
		cur.cnty++;
	}
	else
	{
		cur.cnts++;
	}
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };

	q.push(cur);
	is_visited[cur.x][cur.y]++;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur.cnty > 3)
		{
			continue;
		}
		
		if (cur.cnty + cur.cnts == 7)
		{
			ans++;
			continue;
		}

		for (int i = 0;i < 4;++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (true == in_range(nx, ny) && is_visited[nx][ny] == 0)
			{
				is_visited[nx][ny]++;

				Info Nex = { nx,ny,cur.cnty,cur.cnts };
				if (arr[nx][ny] == 'Y')
				{
					Nex.cnty++;
				}
				else
				{
					Nex.cnts++;
				}
				q.push(Nex);
			}
		}

	}


	return ans;
}

int main()
{
	arr.resize(5);
	for (int i = 0;i < 5;++i)
	{
		arr[i].resize(5);
		for (int j = 0;j < 5;++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0;i < 5;++i)
	{
		for (int j = 0;j < 5;++j)
		{
			ans += bfs(i, j);
		}
	}

	std::cout << ans;

	return 0;
}