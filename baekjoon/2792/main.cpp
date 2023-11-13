#include <iostream>
#include <vector>

int get_count(int num, const std::vector<int>& arr)
{
	int ans = 0;
	for (int cur : arr)
	{
		ans += (cur + num -1) / num;
	}
	return ans;
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> arr;
	arr.resize(m);
	int min = 1, max = 1;
	for (int i = 0;i < m;++i)
	{
		std::cin >> arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	int ans = max;
	while (true)
	{
		if (min > max)
		{
			break;
		}
		int mid = (min + max) / 2;
		if (n < get_count(mid,arr))
		{
			min = mid+1;
		}
		else 
		{
			ans = mid;
			max = mid-1;
		}
	}
	std::cout << min;
	return 0;
}