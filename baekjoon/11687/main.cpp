#include <iostream>

int getexponent(int num)
{
	int ex = 5;
	int cnt = 1;

	int ans = 0;
	while (num >= ex)
	{
		if (num == ex)
		{
			return -1;
		}
		ans += cnt++;
		ex *= 5;
	}
	
	return ans;

}

int main()
{
	int m;
	std::cin >> m;
	int ans = 5 * m;
	int exp = getexponent(m);
	if (exp == -1)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << ans - 5 * exp;
	}

	return 0;
}