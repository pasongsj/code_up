#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;
	int before = 0, cur = 0;
	int ans = 0;
	std::cin >> cur;
	ans = ans > cur - before ? ans : cur - before;
	before = cur;
	for (int i = 1;i < m;++i)
	{
		std::cin >> cur;
		ans = ans > (cur - before + 1) / 2 ? ans : (cur - before + 1) / 2;
		before = cur;
	}
	cur = n;
	ans = ans > cur - before ? ans : cur - before;
	std::cout << ans;
	return 0;
}