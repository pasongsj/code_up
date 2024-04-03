#include <iostream>
#include <vector>


int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> floyd(n + 1, std::vector<int>(n + 1, 100000 * n + 1));

	for (int i = 0;i < m;++i)
	{
		int start, end, cost;
		std::cin >> start >> end >> cost;
		floyd[start][end] = std::min(floyd[start][end], cost);
	}
	for (int i = 1;i <= n;++i)
	{
		floyd[i][i] = 0;
	}

	for (int k=1;k<=n;++k)
	{
		for (int i = 1;i <= n;++i)
		{
			for (int j = 1;j <= n;++j)
			{
				floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= n;++j)
		{
			if (floyd[i][j] == 100000 * n + 1)
			{
				std::cout << '0' << ' ';
			}
			else
			{
				std::cout << floyd[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}

	return 0;
}