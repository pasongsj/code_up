#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> arr;
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(m);
		for (int j = 0;j < m;++j)
		{
			std::cin >> arr[i][j];
		}
	}
	std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
	std::vector<std::vector<bool>> isvisited (n, std::vector<bool>(m, false));
}