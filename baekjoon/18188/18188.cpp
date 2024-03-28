// 18188.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>


int h, w;
std::vector<char> answer;
std::vector<std::vector<char>> arr;
std::vector<std::vector<char>> pair_of_cases;
std::map<char, int> dx = { {'W',-1} ,{'A',0},{'S',1},{'D',0} };
std::map<char, int> dy = { {'W',0} ,{'A',-1},{'S',0},{'D',1} };


bool InRange(int x, int y)
{
	return 0 <= x && x < h && 0 <= y && y < w;
}

bool dfs(int cx, int cy, int index)
{

	if (arr[cx][cy] == 'Z')
	{
		return true;
	}
	if (index >= pair_of_cases.size())
	{
		return false;
	}

	for (char dest : pair_of_cases[index])
	{
		int nx = cx + dx[dest];
		int ny = cy + dy[dest];
		if (true == InRange(nx, ny) && arr[nx][ny] != '@')
		{
			answer.push_back(dest);
			if (true == dfs(nx, ny, index + 1))
			{
				return true;
			}
			answer.pop_back();
		}
	}
	return false;
}

int main()
{
	std::cin >> h >> w;

	int cx = -1, cy = -1;

	arr.resize(h);

	for (int i = 0; i < h; ++i)
	{
		arr[i].resize(w);

		for (int j = 0; j < w; ++j)
		{
			std::cin >> arr[i][j];
			if (arr[i][j] == 'D')
			{
				cx = i, cy = j;
			}
		}
	}
	int move_cnt = 0;
	std::cin >> move_cnt;

	pair_of_cases.resize(move_cnt);
	for (int k = 0; k < move_cnt; ++k)
	{
		char f_m, s_m;
		std::cin >> f_m >> s_m;
		pair_of_cases[k].push_back(f_m);
		pair_of_cases[k].push_back(s_m);
	}

	if (true == dfs(cx, cy, 0))
	{
		std::cout << "YES\n";
		for (char ans : answer)
		{
			std::cout << ans;
		}
	}
	else
	{
		std::cout << "NO";
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
