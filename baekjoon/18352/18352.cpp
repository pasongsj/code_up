// 18352.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

int main()
{
	int n, m, k, s;
	std::cin >> n >> m >> k >> s;
	std::vector<std::vector<int>> graph;
	graph.resize(n + 1, std::vector<int>());
	std::vector<int> weight(n + 1, INT_MAX);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
	}

	std::queue<int> q;
	weight[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : graph[cur])
		{
			if (weight[next] > weight[cur] + 1)
			{
				weight[next] = weight[cur] + 1;
				q.push(next);
			}
		}
	}
	std::vector<int> answer;


	bool isexist = false;
	for (int i = 0; i <= n; ++i)
	{
		if (weight[i] == k)
		{
			std::cout << i << '\n';
			isexist = true;
		}
	}
	if (false == isexist)
	{
		std::cout << -1;
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
