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
		if (recv[i].size() < 2) // 참여할 수 없는놈
		{
			q.push(i);
			cant_participate.push_back(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front(); // 참여할 수 없는 놈
		q.pop();
		if (true == is_remove[cur])
		{
			continue;
		}
		is_remove[cur] = true;
		ans--;

		for (int num : recv[cur]) // 나에게 보낸 기록 지우기
		{
			send[num].erase(cur);
		}

		for (int num : send[cur]) // 내가 보낸거 지우기
		{
			recv[num].erase(cur);
			if (recv[num].size() < 2) // 참여 못할놈 거르기
			{
				q.push(num);
			}
		}
	}
	std::cout << ans << '\n';
	for (int i = 1;i <= n;++i)
	{
		if (!is_remove[i]) // 제거안된놈만 프린트
		{
			std::cout << i << " ";
		}
	}

	return 0;
}