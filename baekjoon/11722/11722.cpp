#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr;
	std::vector<int> dp;

	int answer = 0;
	arr.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		int max = 0;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[i])
			{
				max = max > dp[j] ? max : dp[j];
			}
		}
		dp[i] = max + 1;
		answer = answer > dp[i] ? answer : dp[i];
	}

	std::cout << answer;
	return 0;
}