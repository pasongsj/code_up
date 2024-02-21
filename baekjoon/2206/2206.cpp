#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
//#include <ctime>


std::vector<std::vector<int>> arr;
std::vector<std::vector<int>> dp;
std::vector<std::vector<int>> broke_dp;
int n, m;


bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}


const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };


int main()
{
	//clock_t start, finish;
	//start = clock();
	std::cin >> n >> m;

	arr.resize(n);
	dp.resize(n);
	broke_dp.resize(n);

	for (int i = 0;i < n; ++i)
	{
		arr[i].resize(m);
		dp[i].resize(m);
		broke_dp[i].resize(m);
		

		for (int j = 0; j < m; ++j)
		{
			dp[i][j] = 1000001;
			broke_dp[i][j] = 1000001;
			if (i == n - 1 && j == m - 1)
			{
				int a = 0;
			}
			char tmp;
			std::cin >> tmp;
			arr[i][j] = tmp - '0';
		}
	}

	std::queue<std::pair<int,int>> q;
	dp[0][0] = 1;
	q.push(std::make_pair(0, 0));

	while (!q.empty())
	{
		int cx, cy;
		std::tie(cx, cy) = q.front();
		q.pop();

		for (int i = 0; i < 4;++i)
		{
			bool ischange = false;
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (true == InRange(nx, ny))
			{
				if (0 == arr[nx][ny] && (dp[nx][ny] > dp[cx][cy] + 1 || broke_dp[nx][ny] > broke_dp[cx][cy] + 1))
				{
					ischange = true;
					dp[nx][ny] = std::min(dp[nx][ny], dp[cx][cy] + 1);
					broke_dp[nx][ny] = std::min(broke_dp[nx][ny], broke_dp[cx][cy] + 1);
				}
				else if (1 == arr[nx][ny] && broke_dp[nx][ny] > dp[cx][cy] + 1)
				{
					ischange = true;
					broke_dp[nx][ny] = std::min(broke_dp[nx][ny], dp[cx][cy] + 1);
				}


				if (true == ischange)
				{
					q.push(std::make_pair(nx, ny));
				}
			}
		}
	}

	

	int ans = std::min(broke_dp[n-1][m-1] , dp[n-1][m-1]);
	if (ans == 1000001)
	{
		ans = -1;
	}

	std::cout << ans;
	//finish = clock();
	//double  duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//std::cout << '\n' << duration << "ÃÊ" << std::endl;

	return 0;
}