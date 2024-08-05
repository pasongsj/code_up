// 14938.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

int main()
{
	const int maxlen = 16;
	int n, m, r;
	std::cin >> n >> m >> r;
	std::vector<int> items;
	//std::vector<std::vector<int>> Links(n+1,std::vector<int>(n+1, maxlen));
	std::vector<std::vector<std::pair<int, int>>> Links;

	Links.resize(n + 1);
	items.resize(n + 1);
	for (int i = 1;i <= n;++i)
	{
		std::cin >> items[i];
	}

	for (int j = 0;j < r;++j)
	{
		int start, dest, cost;
		std::cin >> start >> dest >> cost;
		Links[start].push_back(std::make_pair(dest, cost));
		Links[dest].push_back(std::make_pair(start, cost));
		//Links[start][dest] = cost;
		//Links[dest][start] = cost;
	}
	for (int i = 1;i <= n;++i)
	{
		std::vector<int> lastcost(n + 1, maxlen*n);
		lastcost[i] = 0;
		std::queue<std::pair<int,int>> q;
		q.push(std::make_pair(i,0));
		while (!q.empty())
		{
			std::pair<int, int> cur = q.front();
			q.pop();
			if (cur.second > m)
			{
				continue;
			}
			for (const std::pair<int, int>& next : Links[cur.first])
			{
				if (cur.second + next.second < lastcost[next.first])
				{
					q.push(std::make_pair(next.first, cur.second + next.second));
					lastcost[next.first] = (cur.second + next.second);
				}
				
			}

		}
	}

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
