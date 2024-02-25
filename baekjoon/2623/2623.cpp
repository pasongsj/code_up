#include <iostream>
#include <vector>
#include <map>
#include <queue>

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<int> in_degree;

	std::map<int, std::vector<int>> link;
	in_degree.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int cnt, before, after;
		std::cin >> cnt >> before;
		for (int j = 1; j < cnt; ++j)
		{
			std::cin >> after;
			in_degree[after]++;
			link[before].push_back(after);
			before = after;
		}
	}

	std::queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (0 == in_degree[i])
		{
			q.push(i);
		}
	}

	std::vector<int> answer;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		for (int next : link[cur])
		{
			if (0 == --in_degree[next])
			{
				q.push(next);
			}
		}
	}

	if (answer.size() != n)
	{
		std::cout << 0;
	}
	else
	{
		for (int ans : answer)
		{
			std::cout << ans << '\n';
		}
	}
	return 0;
}