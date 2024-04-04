#include <iostream>
#include <vector>
#include <climits>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> arr(n+1, std::vector<int>(m+2, 0));
	
	
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1 ;j <= m;++j)
		{
			std::cin >> arr[i][j];
		}
	}
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+2, INT_MIN/2));

	std::vector<int> lefttmp (m+2,INT_MIN/2);
	std::vector<int> righttmp(m+2,INT_MIN/2);
	dp[1][1] = arr[1][1];

	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= m;++j)
		{
			lefttmp[j] = std::max(lefttmp[j-1], dp[i - 1][j]) + arr[i][j];
			righttmp[m - j + 1] = std::max(righttmp[m - j + 2], dp[i - 1][m - j + 1]) + arr[i][m - j + 1];
			if (i == 1 && j == 1)
			{
				lefttmp[j] = arr[i][j];
			}
		}
		for (int j = 1;j <= m;++j)
		{
			dp[i][j] = std::max(std::max(lefttmp[j], righttmp[j]), dp[i][j]);
		}
	}

	//for (int i = 0;i < n+1;++i)
	//{
	//	for (int j = 0;j <= m+1;++j)
	//	{
	//		std::cout << dp[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}

	std::cout << dp[n][m];

	return 0;
}