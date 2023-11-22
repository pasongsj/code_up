#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, h;
	std::cin >> n >> h;
	std::vector<std::pair<int, int>> cnt;
	for (int i = 0;i < n;++i)
	{
		int tmp;
		std::cin >> tmp;
		if ((i & 1) == 1) // 홀수라면 종유석
		{
			cnt.push_back(std::make_pair(h-tmp, +1));
		}
		else
		{
			cnt.push_back(std::make_pair(tmp, -1));
		}
	}
	cnt.push_back(std::make_pair(h, 0));
	sort(cnt.begin(), cnt.end(), [](const std::pair<int, int> _a, const std::pair<int, int> _b) {	return _a.first < _b.first;});

	int ans = n;
	int samecount = 1;
	int sum = n/2;
	int before = 0;
	for (std::pair<int, int> cur : cnt)
	{
		if (before != cur.first)
		{
			if (ans == sum)
			{
				samecount++;
			}
			else if (ans > sum)
			{
				ans = sum;
				samecount = 1;
			}
			if (cur.first == h)
			{
				break;
			}
			before = cur.first;
		}
		sum += cur.second;
	}

	std::cout << ans << ' ' << samecount;
	return 0;
}
//
//#include <map>
//
//int main()
//{
//	int n, h;
//	std::cin >> n >> h;
//	std::map<int, int> arr;
//	for (int i = 0; i < n; ++i)
//	{
//		int tmp;
//		std::cin >> tmp;
//		if ((i & 1) == 1) // 홀수라면 종유석
//		{
//			for (int j = h - tmp; j <= h; ++j)
//			{
//				arr[j]++;
//			}
//		}
//		else
//		{
//			for (int j = 0; j <= tmp; ++j)
//			{
//				arr[j]++;
//			}
//		}
//	}
//
//	int ans = n;
//	int samecount = 1;
//	for (int i = 0; i <= h; ++i)
//	{
//		if (ans == arr[i])
//		{
//			samecount++;
//		}
//		else if (ans > arr[i])
//		{
//			ans = arr[i];
//			samecount = 1;
//		}
//	}
//	std::cout << ans << ' ' << samecount;
//	return 0;
//}