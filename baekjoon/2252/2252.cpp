#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> orders;
	std::vector<int> weight;
	std::vector<int> result;

	orders.resize(n + 1);
	weight.resize(n + 1);
	result.resize(n + 1);

	for (int i = 0;i < m;++i)
	{
		int before, after;
		std::cin >> before >> after;
		weight[before]++;
		orders[after].push_back(before);
	}

	std::queue<int> q;
	for (int i = 1;i <= n;++i)
	{
		if (weight[i] == 0)
		{
			q.push(i);
			result[i] = 1;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0;i < orders[cur].size();++i)
		{
			int next = orders[cur][i];
			result[next] = std::max(result[next], result[cur] + 1);
			weight[next]--;
			if (weight[next] == 0)
			{
				q.push(next);
			}
		}
	}
	std::vector<std::pair<int, int>> allresult;
	for (int i = 1;i <= n;++i)
	{
		allresult.push_back(std::make_pair(result[i], i));
	}
	sort(allresult.begin(), allresult.end(), [](const std::pair<int, int> a, const std::pair<int, int> b)
		{
			return a.first > b.first;
		});

	for (std::pair<int, int> curnum : allresult)
	{
		std::cout << curnum.second << ' ';
	}
	
	return 0;
}