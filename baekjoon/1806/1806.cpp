#include <iostream>
#include <vector>

int main()
{
	int n, m;
	int start = 0, end = 0;
	std::vector<int> arr;
	std::cin >> n >> m;
	arr.resize(n);
	int sum = 0;
	int answer = 0;
	for (;end < n;++end)
	{
		std::cin >> arr[end];
		sum += arr[end];
		if (sum < m)
		{
			continue;
		}
		while (true)
		{
			if (end <= start || start >= n || sum - arr[start] < m)
			{
				break;
			}
			sum -= arr[start++];
		}
		if (end - start + 1 < answer || 0 == answer)
		{
			answer = end - start + 1;
		}
	}
	std::cout << answer;
	return 0;
}