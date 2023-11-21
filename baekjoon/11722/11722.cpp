#include <iostream>
#include <vector>
#include <algorithm>

int cmp(const std::pair<int, int> a, const std::pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main()
{
	int n;
	std::cin >> n;
	std::vector<std::pair<int,int>> arr;
	std::vector<int> length;

	for (int i = 0;i < n;++i)
	{
		int tmp;
		std::cin >> tmp;
		arr.push_back(std::make_pair(tmp, i));
	}
	std::sort(arr.begin(), arr.end(), cmp);

	length.resize(n);


	return 0;
}