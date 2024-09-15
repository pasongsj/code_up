// 14891.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

int main()
{
	std::vector<std::vector<int>> taws;
	std::vector<int> twvpoints;
	taws.resize(5);
	twvpoints.resize(5);

	for (int i = 1; i < 5; ++i)
	{
		taws[i].resize(8);
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < 8; ++j)
		{
			taws[i][j] = tmp[j] - '0';
		}
	}

	int t;
	std::cin >> t;
	while (t--)
	{
		int index, dir;
		std::cin >> index >> dir;
		std::vector<bool> isvisited(5, false);
		std::queue<std::pair<int, int>> q;

		q.push(std::make_pair(index, dir));
		isvisited[index] = true;
		
		while (!q.empty())
		{
			int ctaw,cdir;
			std::tie(ctaw,cdir) = q.front();
			q.pop();

			if (0 < ctaw + 1 && ctaw + 1 < 5 && false == isvisited[ctaw + 1])
			{
				int ctwv = twvpoints[ctaw];
				int rtwv = twvpoints[ctaw + 1];
				if (taws[ctaw][(ctwv + 2) % 8] != taws[ctaw + 1][(rtwv + 6) % 8])
				{
					q.push(std::make_pair(ctaw + 1, cdir * -1));
				}
				isvisited[ctaw + 1] = true;
			}

			if (0 < ctaw - 1 && ctaw - 1 < 5 && false == isvisited[ctaw - 1])
			{
				int ctwv = twvpoints[ctaw];
				int ltwv = twvpoints[ctaw - 1];
				if (taws[ctaw][(ctwv + 6) % 8] != taws[ctaw - 1][(ltwv + 2) % 8])
				{
					q.push(std::make_pair(ctaw - 1, cdir * -1));
				}
				isvisited[ctaw - 1] = true;
			}

			twvpoints[ctaw] = (twvpoints[ctaw] - cdir + 8) % 8;

		}
	}
	int answer = 0;
	int point = 1;
	for (int i = 1; i < 5; ++i)
	{
		int twv = twvpoints[i];
		if (taws[i][twv] == 1)
		{
			answer += point;
		}
		point *= 2;
	}
	std::cout << answer;
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
