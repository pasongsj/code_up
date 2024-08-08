// 18430.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
int n, m;
int answer;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};


bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
void DFS(int cost, int x, int y, const std::vector<std::vector<int>>& _arr, std::vector<std::vector<bool>>& isvisit)
{
	if (x >= n)
	{
		x = 0;
		y++;
		if(y>=m)
		{
			answer = answer > cost ? answer : cost;
			return;
		}
	}
	for (int i = 0;i < 4;++i)
	{
		if (true == InRange(x + dx[i], y + dy[i]) && true == InRange(x + dx[(i + 1) % 4], y + dy[(i + 1) % 4])&&
			false == isvisit[x + dx[i]][y + dy[i]] && false == isvisit[x + dx[(i + 1) % 4]][y + dy[(i + 1) % 4]] &&
			false == isvisit[x][y])
		{
			isvisit[x][y] = true;
			isvisit[x + dx[i]][y + dy[i]] = true;
			isvisit[x + dx[(i + 1) % 4]][y + dy[(i + 1) % 4]] = true;
			int cnt = _arr[x][y] * 2 + _arr[x + dx[i]][y + dy[i]] + _arr[x + dx[(i + 1) % 4]][y + dy[(i + 1) % 4]];
			DFS(cost + cnt, x + 1, y, _arr, isvisit);
			isvisit[x][y] = false;
			isvisit[x + dx[i]][y + dy[i]] = false;
			isvisit[x + dx[(i + 1) % 4]][y + dy[(i + 1) % 4]] = false;
		}
	}
	DFS(cost, x + 1, y, _arr, isvisit);
}

int main()
{
	answer = 0;
	std::vector<std::vector<int>> arr;
	std::vector<std::vector<bool>> isvisited;
	std::cin >> n >> m;
	arr.resize(n);
	isvisited.resize(n);
	for (int i = 0;i < n;++i)
	{
		arr[i].resize(m);
		isvisited[i].resize(m);
		for (int j = 0;j < m;++j)
		{
			isvisited[i][j] = false;
			std::cin >> arr[i][j];
		}
	}

	DFS(0, 0, 0, arr, isvisited);

	std::cout << answer;
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
