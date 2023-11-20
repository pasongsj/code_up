#include <iostream>
#include <vector>
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> input;
	input.resize(n);
	int max = 0;
	for (int i = 0;i < n;++i)
	{
		std::cin >> input[i];
		max = max > input[i] ? max : input[i];
	}

	std::vector<int>arr;
	arr.resize(max + 3);
	arr[1] = 1, arr[2] = 2, arr[3] = 4;	// 111, 12,21,3
	for (int i = 4;i <= max;++i)
	{
		if (i - 1 > 0)
		{
			arr[i] += arr[i - 1];
		}
		if (i - 2 > 0)
		{
			arr[i] += arr[i - 2];
		}
		if (i - 3 > 0)
		{
			arr[i] += arr[i - 3];
		}
	}
	for (int i = 0;i < n;++i)
	{
		std::cout << arr[input[i]] << '\n';
	}
	return 0;
}