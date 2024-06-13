#include <iostream>
#include <vector>
#include <tuple>

int n, m;
std::vector<std::vector<int>> arr;
std::vector<std::pair<int, int>> monitors;
int answer;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

void Comp(const std::vector<std::vector<bool>>& Isvisited)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (false == Isvisited[i][j] && 6 != arr[i][j])
			{
				cnt++;
			}
		}
	}
	answer = answer > cnt ? cnt : answer;
}

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void MakeCheck(int x, int y, int dir, std::vector<std::vector<bool>>& Isvistied)
{
	int range = 0;
	while (true)
	{
		int nx = x + dx[dir] * range;
		int ny = y + dy[dir] * range;

		if (false == InRange(nx, ny) || 6 == arr[nx][ny])
		{
			break;
		}
		Isvistied[nx][ny] = true;
		range++;
	}
}

void DFS(int index,int dir, std::vector<std::vector<bool>> Isvistied)
{
	int x, y;
	std::tie(x, y) = monitors[index];
	int cur_mon = arr[x][y];
	if (1 == cur_mon)
	{
		MakeCheck(x, y, dir, Isvistied);
	}
	else if (2 == cur_mon)
	{
		MakeCheck(x, y, dir, Isvistied);
		MakeCheck(x, y, (dir + 2) % 4, Isvistied);
	}
	else if (3 == cur_mon)
	{
		MakeCheck(x, y, dir, Isvistied);
		MakeCheck(x, y, (dir + 1) % 4, Isvistied);
	}
	else if (4 == cur_mon)
	{
		MakeCheck(x, y, dir, Isvistied);
		MakeCheck(x, y, (dir + 1) % 4, Isvistied);
		MakeCheck(x, y, (dir + 2) % 4, Isvistied);
	}
	else if (5 == cur_mon)
	{
		MakeCheck(x, y, dir, Isvistied);
		MakeCheck(x, y, (dir + 1) % 4, Isvistied);
		MakeCheck(x, y, (dir + 2) % 4, Isvistied);
		MakeCheck(x, y, (dir + 3) % 4, Isvistied);
	}

	index++;
	if (index == monitors.size())
	{
		Comp(Isvistied);

		return;
	}

	std::tie(x, y) = monitors[index];
	cur_mon = arr[x][y];

	if (1 == cur_mon)
	{
		for (int i = 0; i < 4; ++i)
		{
			DFS(index, i, Isvistied);
		}
	}
	else if (2 == cur_mon)
	{
		for (int i = 0; i < 2; ++i)
		{
			DFS(index, i, Isvistied);
		}
	}
	else if (3 == cur_mon)
	{
		for (int i = 0; i < 4; ++i)
		{
			DFS(index, i, Isvistied);
		}
	}
	else if (4 == cur_mon)
	{
		for (int i = 0; i < 4; ++i)
		{
			DFS(index, i, Isvistied);
		}
	}
	else if (5 == cur_mon)
	{
		DFS(index, 0, Isvistied);
	}
}


int main()
{
	std::vector<std::vector<bool>> IsVisited;
	std::cin >> n >> m;

	arr.resize(n);
	IsVisited.resize(n);
	answer = n * m;

	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(m);
		IsVisited[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> arr[i][j];
			IsVisited[i][j] = false;
			if (arr[i][j] != 0 && arr[i][j] != 6)
			{
				monitors.push_back(std::make_pair(i, j));
			}
		}
	}
	if (monitors.size() == 0)
	{
		Comp(IsVisited);
	}
	else
	{
		int index = 0;
		int x, y;
		std::tie(x, y) = monitors[index];
		int cur_mon = arr[x][y];

		if (1 == cur_mon)
		{
			for (int i = 0; i < 4; ++i)
			{
				DFS(index, i, IsVisited);
			}
		}
		else if (2 == cur_mon)
		{
			for (int i = 0; i < 4; ++i)
			{
				DFS(index, i, IsVisited);
			}
		}
		else if (3 == cur_mon)
		{
			for (int i = 0; i < 4; ++i)
			{
				DFS(index, i, IsVisited);
			}
		}
		else if (4 == cur_mon)
		{
			for (int i = 0; i < 4; ++i)
			{
				DFS(index, i, IsVisited);
			}
		}
		else if (5 == cur_mon)
		{
			DFS(index, 0, IsVisited);
		}
	}


	std::cout << answer;


	return 0;
}