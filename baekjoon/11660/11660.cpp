#include <iostream>
#include <vector>

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> arr(n + 1, std::vector<int>(n + 1, 0));
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= n;++j)
		{
			std::cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	std::vector<int> answer;
	for (int j = 0;j < m;++j)
	{
		int sx, sy, dx, dy;
		std::cin >> sx >> sy >> dx >> dy;
		answer.push_back(dp[dx][dy] - dp[sx - 1][dy] - dp[dx][sy - 1] + dp[sx - 1][sy - 1]);
	}

	for (int ans : answer)
	{
		std::cout << ans << '\n';
	}
	return 0;

}