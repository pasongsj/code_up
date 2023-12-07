#include <iostream>
#include <vector>
#include<set>

std::vector<std::set<int>> ancestor; // 선행노드
std::vector<int> cnt; // 현재건물 짓는데 드는 시간
std::vector<int> res; // 최종시간

int getalldp(int num)
{
	if (ancestor[num].size() == 0)
	{
		return res[num];
	}
	int ans = 0;
	for (int n : ancestor[num])
	{
		ans += getalldp(n);
	}
	res[num] += ans;
	ancestor[num].clear();
	return res[num];
}

int main()
{

	int n;
	std::cin >> n;
	ancestor.resize(n + 1);
	cnt.resize(n + 1);
	res.resize(n + 1);
	for (int i = 1;i <= n;++i)
	{
		std::cin >> cnt[i];
		res[i] = cnt[i];

		int tmp = 0;
		while (true)
		{
			std::cin >> tmp;
			if (tmp == -1)
			{
				break;
			}
			ancestor[i].insert(tmp);
		}

	}

	for (int i = 1;i <= n;++i)
	{
		getalldp(i);

	}
	return 0;
}