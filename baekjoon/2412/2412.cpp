// 2412.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>


int main()
{
	int n, T;
	std::cin >> n >> T;
	int answer = 5000001;
	std::vector<std::pair<int, int>> points;
	std::vector<bool> isvisted(n, false);


	points.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> points[i].first >> points[i].second;
	}
	std::sort(points.begin(), points.end());




	std::queue<std::tuple<int,int,int>> q;
	q.push(std::make_tuple(0, 0, 0));

	while (!q.empty())
	{
		std::tuple<int, int,int> cur = q.front();
		int x, y, m;
		std::tie(x, y, m) = cur;
		q.pop();
		if (y == T)
		{
			answer = m;
			break;
		}

		auto start = std::lower_bound(points.begin(), points.end(), std::make_pair(x - 2, y - 2));
		auto last = std::upper_bound(points.begin(), points.end(), std::make_pair(x + 2, y + 2));

		for (; start != last; start++)
		{
			if (false == isvisted[start - points.begin()] && abs(y - start->second)<=2)
			{
				isvisted[start - points.begin()] = true;
				q.push(std::make_tuple(start->first, start->second, m + 1));
			}
		}

	}

	if (5000001 == answer)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << answer;
	}
	return 0;
}
// 0,0 to 6,3
// 0,0 to 1,2
// 1,2 to 3,2
// 3,2 tO 4,1
// 4,1 tO 6,3
// 
// 
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
