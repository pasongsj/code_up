#include <iostream>
#include <vector>
int main()
{
	int t;
	std::cin >> t;
	std::vector<int> answer;
	while (t--)
	{
		int n, m;
		std::cin >> n >> m;

		int s = n < (m - n) ? n : m - n;
		int ans = 1;
		for (int i = 0;i < s;++i)
		{
			ans *= (m - i);
			ans /= (i + 1);
		}
		answer.push_back(ans);
	}

	for (int ans : answer)
	{
		std::cout << ans << '\n';
	}
	return 0;
}