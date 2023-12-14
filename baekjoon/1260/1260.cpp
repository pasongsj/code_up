#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
std::vector<std::set<int>> graph;


void dfs(int x, std::map<int,bool>& isvisited)
{
	isvisited[x] = 1;
	std::cout << x << " ";
	for (int i : graph[x])
	{
		if (1 != isvisited[i]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
		{
			dfs(i, isvisited); // 재귀적으로 방문
		}
	}
}

void bfs(int x, std::map<int, bool>& isvisited)
{
	std::queue<int> q;
	q.push(x);
	isvisited[x] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		std::cout << cur << ' ';
		q.pop();
		for (int j : graph[cur])
		{
			if (1 != isvisited[j])
			{
				q.push(j);
				isvisited[j] = 1;
			}
		}
	}
}


int main()
{
	int n, m, v;
	std::cin >> n >> m >> v;

	graph.resize(n + 1);
	std::map<int, bool> isvisited;
	//std::vector<bool> isvisited(m + 1, false);

	for (int i = 0; i < m; ++i)
	{
		int from, to;
		std::cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}
	dfs(v,isvisited);
	isvisited.clear();
	std::cout << '\n';
	bfs(v,isvisited);
}