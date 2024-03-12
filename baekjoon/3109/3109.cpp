#include <iostream>
#include <vector>

const int dx[3] = { -1,0,1 };
const int dy[3] = { 1,1,1, };

std::vector<std::vector<char>> arr;
std::vector<std::vector<int>> is_visited;
int r, c;

bool InRange(int x, int y)
{
	return 0 <= x && x < r && 0 <= y && y < c;
}

bool dfs(int i, int j)
{
	if (j == c - 1)
	{
		return true;
	}
	for (int k = 0; k < 3; ++k)
	{
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (true == InRange(nx,ny) && 0 == is_visited[nx][ny] && '.' == arr[nx][ny])
		{
			is_visited[nx][ny] = 1;
			if (true == dfs(nx, ny))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	std::cin >> r >> c;

	// 입력을 받는다.
	arr.resize(r);
	is_visited.resize(r);
	for (int i = 0; i < r; ++i)
	{
		arr[i].resize(c);
		is_visited[i].resize(c);
		for (int j = 0; j < c; ++j)
		{
			std::cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < r; ++i)
	{
		is_visited[i][0] = 1;
		if (true == dfs(i, 0))
		{
			ans++;
		}
	}
	std::cout << ans;
	return 0;
}