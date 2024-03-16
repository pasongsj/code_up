#include <iostream>
#include <vector>

#include <queue>

int main()
{
	int n; // 컴퓨터 수
	int paircnt; // 연결 쌍 수

	std::cin >> n >> paircnt;


	std::vector<int> is_visited(n+1, false); //방문체크
	std::vector<std::vector<int>> link(n+1, std::vector<int>()); //연결
	
	for (int i = 0; i < paircnt; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	//bfs
	std::queue<int> q;
	q.push(1);
	is_visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : link[cur])
		{
			if (false == is_visited[next])
			{
				is_visited[next] = true;
				q.push(next);
			}
		}
	}
	int answer = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (true == is_visited[i])
		{
			answer++;
		}
	}

	std::cout << answer;
	return 0;
}