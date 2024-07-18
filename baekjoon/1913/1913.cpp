﻿// 1913.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


void GetNext(int& cx, int& cy, int& dir, int bound, int center)
{
	int nx = cx + dx[dir];
	int ny = cy + dy[dir];

	if (
		center - bound <= nx && nx <= center + bound &&
		center - bound <= ny && ny <= center + bound
		)
	{
		cx = nx;
		cy = ny;
		return;
	}
	else
	{
		dir = (dir + 1) % 4;
		cx = cx + dx[dir];
		cy = cy + dy[dir];
	}
}


int main()
{
	int n;
	int dest;
	std::cin >> n >> dest;
	std::vector<std::vector<int>> arr(n+1,std::vector<int>(n+1,0));
	
	int num = 1;
	int bound = 1;

	int centerx = (n + 1) / 2, centery = (n + 1) / 2;
	int cx = centerx, cy = centery;

	int dir = 0;

	arr[cx][cy] = num++;
	while (true)
	{
		if (num > (bound * 2 + 1) * (bound * 2 + 1))
		{
			bound ++;
		}
		
		GetNext(cx, cy, dir, bound, (n + 1) / 2);
		arr[cx][cy] = num++;

		if (num >= n * n + 1)
		{
			break;
		}
	}
	
	int answerx, answery;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cout << arr[i][j] << ' ';
			if (arr[i][j] == dest)
			{
				answerx = i;
				answery = j;
			}
		}
		std::cout << '\n';
	}
	std::cout << answerx << ' ' << answery;
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
