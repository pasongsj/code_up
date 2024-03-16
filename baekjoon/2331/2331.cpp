#include <iostream>
#include <set>
#include <cmath>


int GetCal(int n, int p)
{
	int ans = 0;
	while (n > 0)
	{
		ans += std::pow(n % 10, p);
		n /= 10;
	}
	return ans;
}

int main()
{
	int num,p;
	std::cin >> num >> p;
	std::set<int> arr;
	bool is_loop = false;
	while (true)
	{
		if (false == is_loop)
		{
			if (arr.end() == arr.find(num)) // 새로운 number이라면
			{
				arr.insert(num);
			}
			else
			{
				is_loop = true;
				arr.erase(num);
			}
		}
		else
		{
			if (arr.end() == arr.find(num))
			{
				break;
			}
			else
			{
				arr.erase(num);
			}
		}
		num = GetCal(num, p);
	}
	std::cout << arr.size();
	return 0;
}