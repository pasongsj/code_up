#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> remainnum;
std::vector<int> curnum;
std::set<int> allnum;


void Print()
{
	for (int num : curnum)
	{
		std::cout << num << ' ';
	}
	std::cout << '\n';
}

void calcul(int m)
{
	if (curnum.size() == m)
	{
		Print();
		return;
	}

	for (int num : allnum)
	{
		if (remainnum[num] > 0)
		{
			remainnum[num]--;
			curnum.push_back(num);
			calcul(m);
			curnum.pop_back();
			remainnum[num]++;
		}
	}

}

int main()
{
	int n, m;
	std::cin >> n >> m;
	remainnum.resize(10000+1);

	for (int i = 0;i < n;++i)
	{
		int tmp;
		std::cin >> tmp;
		remainnum[tmp]++;
		allnum.insert(tmp);
	}
	calcul(m);	

	return 0;
}
