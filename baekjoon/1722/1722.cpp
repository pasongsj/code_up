#include <iostream>
#include <vector>
#include <set>

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::vector<long long> factorial;
	factorial.resize(n+1);
	factorial[0] = 1;
	std::vector<long long> notused;

	for (int i = 1;i <= n;++i)
	{
		factorial[i] = factorial[i - 1] * i;
		notused.push_back(i);
	}
	//factorial[0] = 0;

	if (k == 1)
	{
		std::vector<int> ans;
		ans.resize(n);
		int index;
		std::cin >> index;
		//--index;
		//index++;
		for (int i = n - 1;i >= 0;i--)
		{
			int curindex = index / factorial[i];
			if (index == 1)
			{
				curindex = 0;
			}

			auto it = notused.begin();
			it += curindex;
			ans[i] = *it;
			index %= factorial[i];
			notused.erase(it);
		}

		for (int i = n - 1;i >= 0;--i)
		{
			std::cout << ans[i] << ' ';
		}
	}
	else if (k == 2)
	{
		long long ans = 0;
		std::vector<int> compare;
		for (int i = n;i > 0;--i)
		{
			int tmp;
			std::cin >> tmp;
			auto it = find(notused.begin(), notused.end(), tmp);
			ans += (it - notused.begin()) * factorial[i - 1];

			notused.erase(it);
		}
		std::cout << ans + 1;
	}


	return 0;

}
