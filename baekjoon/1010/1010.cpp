#include <iostream>
#include <vector>

int GetCase(int n, int r)
{
	int ans = 1;
	for (int i = 0; i < r; ++i)
	{
		ans *= (n - i);
		ans /= (i + 1);
	}
	return ans;
}

int main()
{
	int m;
	std::cin >> m;
	std::vector<int> answer;

	for (int i = 0; i < m; ++i)
	{
		int r, n;

		std::cin >> r >> n;
		answer.push_back(GetCase(n, r));
	}
	for (int ans : answer)
	{
		std::cout << ans << '\n';
	}
	return 0;
}