#include <iostream>
#include <vector>
#include <tuple>
#include <set>

int main()
{
	int n;
	std::cin >> n;
	std::multiset<std::pair<int, int>> arr;

	for (int i = 0;i < n;++i)
	{
		int tmp;
		std::cin >> tmp;
		if (tmp < 0)
		{
			arr.insert(std::make_pair(abs(tmp), -1));
		}
		else
		{
			arr.insert(std::make_pair(abs(tmp), +1));
		}
	}

	auto it = arr.begin();
	int last = it->first * it->second;
	it++;
	int diff = 2000000000;
	int ans1, ans2;
	for (;it != arr.end(); it++)
	{
		int cur = it->first * it->second;
		if (abs(cur+last) < diff)
		{
			ans1 = std::min(last,cur);
			ans2 = std::max(cur,last);
			diff = abs(cur + last);
		}
		last = cur;
	}
	std::cout << ans1 << ' ' << ans2;

	return 0;
}