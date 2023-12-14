#include <iostream>
#include <vector>

#include <map>
#include <algorithm>

std::vector<int> Parentnode;

int FindParent(int num)
{
	if (Parentnode[num] == num)
	{
		return num;
	}
	return FindParent(Parentnode[num]);
}

void mergeParent(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);
	if (a == b)
	{
		return;
	}
	if (a < b)
	{
		Parentnode[b] = a;
	}
	else
	{
		Parentnode[a] = b;

	}
}

int main()
{
	std::vector<std::vector<int>> arr = { {1,2},{2,3},{3,4},{4,1},
											{5,4},{5,9},{9,6},{9,8},{6,7},{8,7},
											{11,12},{11,10},{12,9},{10,9} };
	int n = 12;


	std::vector<int> answer;
	answer.resize(3);

	//정점을 찾자
	int staticpoint = 0;
	Parentnode.resize(n + 1);
	for (const std::vector<int>& cur : arr)
	{
		Parentnode[cur[0]]++;
		staticpoint = Parentnode[cur[0]] > Parentnode[staticpoint] ? cur[0] : staticpoint;
	}


	for (int i = 1; i <= n; ++i)
	{
		Parentnode[i] = i;
	}

	std::vector<int> line;
	line.resize(n + 1);
	for (const std::vector<int>& cur : arr)
	{
		if (cur[0] == staticpoint)
		{
			continue;
		}
		
		mergeParent(cur[0], cur[1]);
		line[cur[0]]++;
	}

	int a = 0;

	std::map<int, int> vertices;
	std::map<int, int> edges;
	for (int i = 1; i <= n; ++i)
	{
		if (staticpoint == i)
		{
			continue;
		}
		int curnum = FindParent(Parentnode[i]);
		vertices[curnum]++;
		edges[curnum] += line[i];
	}

	for (const std::pair<int, int>& bun : vertices)
	{
		int rootnum = bun.first;
		int vertex = vertices[rootnum];
		int edge = edges[rootnum];
		if (vertex + 1 == edge)
		{
			answer[2]++;
		}
		else if (vertex - 1  == edge)
		{
			answer[1]++;
		}
		else if (vertex == edge)
		{
			answer[0]++;

		}
	}

	std::cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];

	return 0;
}