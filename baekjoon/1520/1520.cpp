#include <iostream>
#include <vector>
//#include <time.h>

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int n, m;

std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> dp_arr;
std::vector<std::vector<int>> isvisited;

bool in_range(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		return 1;
	}
	if (1 == isvisited[x][y]) {
		return dp_arr[x][y];
	}
	isvisited[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (true == in_range(nx, ny) && arr[x][y] > arr[nx][ny])
		{
			dp_arr[x][y] += dfs(nx, ny);
		}
	}
	return dp_arr[x][y];
}

int main()
{
	//clock_t start, finish;
	//start = clock();

	std::cin >> n >> m;

	arr.resize(n);
	dp_arr.resize(n);
	isvisited.resize(n);

	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(m);
		dp_arr[i].resize(m);
		isvisited[i].resize(m);

		for (int j = 0;j < m; ++j)
		{
			std::cin >> arr[i][j];
		}
	}
	
	int ans = dfs(0, 0);

	std::cout << ans;

	//finish = clock();
	//double  duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//std::cout <<'\n' << duration << "ÃÊ" << std::endl;
	return 0;

}