// 3190.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> arr;
std::vector<std::pair<int, char>> dirchange;
std::queue<std::pair<int, int>> trail;
int n;
int answer;
int dirindex;

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(std::pair<int, int> head, int dir, int cnt)
{
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1,0 };

	answer = answer > cnt ? answer : cnt;
	if (dirindex <dirchange.size() && dirchange[dirindex].first == cnt)
	{
		if (dirchange[dirindex].second == 'D')
		{
			dir = (dir + 1) % 4;
		}
		else
		{
			dir = (dir + 3) % 4;
		}
		dirindex++;
	}

	int nx = head.first + dx[dir];
	int ny = head.second + dy[dir];

	if (false == InRange(nx, ny) || -1 == arr[nx][ny])
	{
		return;
	}
	else if (0 == arr[nx][ny])
	{
		std::pair<int, int> tail = trail.front();
		trail.pop();
		arr[tail.first][tail.second] = 0;
		trail.push(std::make_pair(nx, ny));
		arr[nx][ny] = -1;
		DFS(std::make_pair(nx, ny), dir, cnt + 1);
	}
	else if (1 == arr[nx][ny])
	{
		trail.push(std::make_pair(nx, ny));
		arr[nx][ny] = -1;
		DFS(std::make_pair(nx, ny), dir, cnt + 1);
	}
}

int main()
{

	std::cin >> n;
	arr.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(n);
	}

	int ap;
	std::cin >> ap;
	for (int i = 0;i < ap;++i)
	{
		int a, b;
		std::cin >> a >> b;
		arr[--a][--b] = 1;
	}

	int dcnt;
	std::cin >> dcnt;

	for (int i = 0;i < dcnt;++i)
	{
		int x;
		char d;
		std::cin >> x >> d;
		dirchange.push_back(std::make_pair(x, d));
	}

	answer = 0;
	dirindex = 0;
	trail.push(std::make_pair(0, 0));
	DFS(std::make_pair(0, 0), 0, 0);
	std::cout << answer+1;

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
