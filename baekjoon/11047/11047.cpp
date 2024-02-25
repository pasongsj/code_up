#include <iostream>
#include <vector>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> coins;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		coins.emplace_back(tmp);
	}
	int answer = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		answer += (k / coins[i]);
		k %= coins[i];
	}
	std::cout << answer;
	return 0;
}