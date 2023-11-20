#include <iostream>
#include <vector>

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	std::vector<int> arr;
	int n;
	std::cin >> n;
	arr.resize(n+3);
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4;i <= n;++i)
	{
		arr[i] = 1e6;
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i],arr[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		arr[i] = min(arr[i], arr[i -1 ] + 1);
	}
	std::cout << arr[n];
	return 0;
}