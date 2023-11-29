#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> right;
	std::vector<int> left;
	right.resize(m);
	left.resize(m);
	for (int i = 0;i < m;++i)
	{
		std::cin >> left[i];
	}
	int curmax = 0;
	for (int i = m - 1;i >= 0;i--)
	{
		curmax = curmax > left[i] ? curmax : left[i];
		right[i] = curmax;
	}
	curmax = 0;
	int answer = 0;
	for (int i = 0;i < m;++i)
	{
		curmax = curmax > left[i] ? curmax : left[i];
		int h = curmax < right[i] ? curmax : right[i];
		if (left[i] < h)
		{
			answer += (h - left[i]);
		}
	}
	std::cout << answer;


	return 0;
}
