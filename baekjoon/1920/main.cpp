#include <iostream>
#include <set>
#include <algorithm>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;
	std::cin >> n;
	std::set<int> arr;
	for (int i = 0;i < n;++i)
	{
		int tmp;
		std::cin >> tmp;
		arr.insert(tmp);
	}
	std::cin >> m;
	for (int i = 0;i < m;++i)
	{
		int tmp;
		std::cin >> tmp;
		if (arr.end() == arr.find(tmp))
		{
			std::cout << "0\n";
		}
		else
		{
			std::cout << "1\n";
		}
	}
	return 0;

}