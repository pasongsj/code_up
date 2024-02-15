#include <iostream>
#include <vector>

#include <queue>
#include <tuple>
#include <algorithm>

std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> ans;
int n;

bool in_range(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}


int GetMax(int x, int y) {
	if (ans[x][y] > 0)
	{
		return ans[x][y];
	}
	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = {0,0,1,-1};

	int cnt = 0;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = x + dy[i];

		if (true == in_range(nx, ny) && arr[nx][ny] > arr[x][y])
		{
			cnt = std::max(cnt, GetMax(nx, ny));
		}
	}

	return ans[x][y] = cnt + 1;
}

int main()
{
	std::cin >> n;

	arr.resize(n);
	ans.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(n);
		ans[i].resize(n);
		for (int j = 0;j < n;++j)
		{
			std::cin >> arr[i][j];
		}
	}
	int answer = 1;

	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			answer = std::max(GetMax(i, j), answer);
		}
	}
	std::cout << answer;


	return 0;
}