#include <iostream>
#include <vector>
#include <map>

bool in_range(int n)
{
	return 0 <= n && n <= 20;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> nums;
	std::vector<std::vector<long long>> sums;
	nums.resize(n);
	sums.resize(n);
	for (int i = 0;i < n;++i)
	{
		sums[i].resize(21);

		std::cin >> nums[i]; // cur number

		if (i == 0)
		{
			sums[i][nums[i]]++;
			continue;
		}
		if (i == n - 1)
		{
			std::cout << sums[i - 1][nums[i]];
			return 0;
		}
		for (int j = 0;j <= 20;++j)
		{
			if (in_range(j-nums[i]) && in_range(j))
			{
				sums[i][j- nums[i]] += sums[i - 1][j];
			}
			if (in_range(j + nums[i]) && in_range(j))
			{
				sums[i][j + nums[i]] += sums[i - 1][j];
			}
		}
	}
	
	return 0;
}