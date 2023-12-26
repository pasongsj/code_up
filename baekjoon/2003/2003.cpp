#include <iostream>
#include <vector>

int main()
{
	int n, m;
	std::vector<int> arr;

	int answer = 0;
	std::cin >> n >> m;
	arr.resize(n);
	int sum = 0;
	int start = 0, end = 0;
	for (;end < n;++end)
	{
		std::cin >> arr[end];
		sum += arr[end];
		
		while (sum > m&&start <n && start<end)
		{
			sum -= arr[start++];
		}
		if (sum == m)
		{
			answer++;
		}
	}

	std::cout << answer;

	return 0;
}