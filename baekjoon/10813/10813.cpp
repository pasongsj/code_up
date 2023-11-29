#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> basket;
	basket.resize(n + 1);
	for (int i = 1;i <= n ;++i)
	{
		basket[i] = i;
	}
	for (int x = 0;x < m;++x)
	{
		int i, j, tmp;
		std::cin >> i >> j;
		tmp = basket[i];
		basket[i] = basket[j];
		basket[j] = tmp;
	}
	for (int i = 1;i <= n;++i)
	{
		std::cout << basket[i] << ' ';
	}

	return 0;
}


// 2 1 3 4 5
// 2 1 4 3 5
// 3 1 4 2 5
// 3 1 4 2 5