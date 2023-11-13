#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int main()
{
	int n, c;
	std::map<int, int> arr;
	std::map<int, int> index;
	std::cin >> n >> c;
	for (int i = 1;i <= n;++i)
	{
		int tmp;
		std::cin >> tmp;
		arr[tmp]++;
		if (0 == index[tmp])
		{
			index[tmp] = i;
		}
	}
	std::vector<std::pair<int, int>> vec(arr.begin(), arr.end());
	sort(vec.begin(), vec.end(), [&index](std::pair<int, int> a, std::pair<int, int> b) {
		if (a.second == b.second)
		{
			return index[a.first] < index[b.first];
		}
		return a.second > b.second;
		});

	for (std::pair<int, int> _p : vec)
	{
		for (int i = 0;i < _p.second;++i)
		{
			std::cout << _p.first << ' ';
		}
	}
	return 0;
}