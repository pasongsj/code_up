#include <iostream>
#include <vector>

#include <queue>


int main()
{
	int N, M, K, X;
	std::cin >> N >> M >> K >> X;
	std::vector<std::vector<int>> move(N + 1, std::vector<int>());
	std::vector<int> weights(N + 1, 300000000);

	for (int i = 0;i < M;++i)
	{
		int node_f, node_d;
		std::cin >> node_f >> node_d;
		move[node_f].push_back(node_d);
	}


	std::queue<int> q;
	q.push(X);
	weights[X] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : move[cur])
		{
			if (weights[next] > weights[cur] + 1)
			{
				weights[next] = weights[cur] + 1;
				q.push(next);
			}
		}
	}

	std::vector<int> answervec;

	for (int i = 1;i <= N;++i)
	{
		if (K == weights[i])
		{
			answervec.push_back(i);
		}
	}
	
	if (0 == answervec.size())
	{
		std::cout << -1;
	}
	else
	{
		for (int ans : answervec)
		{
			std::cout << ans << '\n';
		}
	}
	return 0;
}