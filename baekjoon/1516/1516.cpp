#include <iostream>
#include <vector>
#include<set>

std::vector<std::set<int>> ancestor; // ������ - ����
std::vector<int> cnt; // ����ǹ� ���µ� ��� �ð�
std::vector<int> res; // �����ð�

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


#include <queue>
std::vector<int> entry; // ��������

int main()
{

	int n;
	std::cin >> n;
	ancestor.resize(n + 1);
	cnt.resize(n + 1);
	res.resize(n + 1);
	entry.resize(n + 1);

	std::queue<int> q;
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
			ancestor[tmp].insert(i);
			entry[i]++;
		}
		if (0 == entry[i])
		{
			q.push(i);
		}
	}



	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int num : ancestor[cur])
		{
			res[num] = std::max(res[num], res[cur] + cnt[num]);
			ancestor[num].erase(cur);
			entry[num]--;
			if (entry[num] == 0)
			{
				q.push(num);
			}
		}
	}

	for (int i=0;i<=n;++i)
	{
		std::cout << res[i] << '\n';
	}
	//for (int i = 1;i <= n;++i)
	//{
	//	getalldp(i);
	//}
	return 0;
}