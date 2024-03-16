#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<std::vector<bool>> is_visited;
std::vector<std::vector<int>> arr;

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int DFS(int x, int y)
{
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };
	int ans = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (true == InRange(nx, ny) && false == is_visited[nx][ny] && 1 == arr[nx][ny])
		{
			is_visited[nx][ny] = true;
			ans += DFS(nx, ny);
		}
	}
	return ans;
}

int main()
{
	std::cin >> n;

	is_visited.resize(n);
	arr.resize(n);

	for (int i = 0; i < n; ++i)
	{
		is_visited[i].resize(n);
		arr[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			is_visited[i][j] = false;
			char tmpinput;
			std::cin >> tmpinput;
			arr[i][j] = tmpinput - '0';
		}
	}

	std::vector<int> answer;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (false == is_visited[i][j] && 1 == arr[i][j])
			{
				is_visited[i][j] = true;
				answer.push_back(DFS(i, j));
			}
		}
	}
	std::sort(answer.begin(), answer.end());
	std::cout << answer.size() << '\n';
	for (int ans : answer)
	{
		std::cout << ans << '\n';
	}
	return 0;
}
