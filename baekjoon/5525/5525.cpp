#include <iostream>
#include <string>
int main()
{
	int ans = 0;
	int n, m;
	std::string arr;
	std::cin >> n >> m >> arr;

	int start = 0, end = 0;
	int cnt = 0;
	for (int i = 2; i < m;)
	{
		if (arr[i - 2] == 'I' && arr[i - 1] == 'O' && arr[i] == 'I')
		{
			cnt++;
			i += 2;
		}
		else
		{
			cnt = 0;
			i++;
		}
		if (cnt >= n)
		{
			ans++;
		}
	}
	std::cout << ans;
	return 0;
}