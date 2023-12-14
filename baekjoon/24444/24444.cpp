#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

int main()
{
	int n, m, r;
	std::cin >> n >> m >> r;

	std::vector<int> answer;
	std::map<int, std::set<int>> graph;
	std::map<int, bool> isvisited;

	answer.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
		isvisited[a] = false;
		isvisited[b] = false;
	}

	std::queue<int> q;
	q.push(r);
	isvisited[r] = true;
	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer[cur] = cnt++;

		for (int i : graph[cur])
		{
			if (true == isvisited[i])
			{
				continue;
			}
			q.push(i);
			isvisited[i] = true;

		}

	}

	for (int i = 1; i <=n; ++i)
	{
		std::cout<<answer[i]<<'\n';
	}
	return 0;
}
