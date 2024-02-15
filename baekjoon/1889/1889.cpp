#include <iostream>
#include <vector>
#include <queue>
#include <set>

int main()
{
	int n;
	std::cin >> n;
	std::vector<std::set<int>> recv;
	std::vector<std::set<int>> send;
	std::vector<int> is_remove;

	is_remove.resize(n + 1);
	recv.resize(n + 1);
	send.resize(n + 1);


	for (int i = 0;i < n;++i)
	{
		is_remove[i + 1] = false;
		int a, b;
		std::cin >> a >> b;
		recv[a].insert(i+1);
		recv[b].insert(i+1);
		send[i + 1].insert(a);
		send[i + 1].insert(b);
	}
	std::vector<int> cant_participate;
	std::queue<int> q;
	
	int ans = n;
	for (int i = 1;i <= n;++i)
	{
		if (recv[i].size() < 2) // ������ �� ���³�
		{
			q.push(i);
			cant_participate.push_back(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front(); // ������ �� ���� ��
		q.pop();
		if (true == is_remove[cur])
		{
			continue;
		}
		is_remove[cur] = true;
		ans--;

		for (int num : recv[cur]) // ������ ���� ��� �����
		{
			send[num].erase(cur);
		}

		for (int num : send[cur]) // ���� ������ �����
		{
			recv[num].erase(cur);
			if (recv[num].size() < 2) // ���� ���ҳ� �Ÿ���
			{
				q.push(num);
			}
		}
	}
	std::cout << ans << '\n';
	for (int i = 1;i <= n;++i)
	{
		if (!is_remove[i]) // ���žȵȳ� ����Ʈ
		{
			std::cout << i << " ";
		}
	}

	return 0;
}