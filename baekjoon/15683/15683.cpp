// 15683.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
int n, m;
std::vector<std::vector<int>> arr;
std::vector<std::vector<bool>> IsVisited;

const int dx[4] = { 0,1,0,-1 }; // 동 남 서 북
const int dy[4] = { 1,0,-1,0 };

bool InRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void MakeVisit(int x, int y, int dir)
{
	int range = 1;
	while (true)
	{
		int nx = x + dx[dir] * range;
		int ny = y + dy[dir] * range;

		if (false == InRange(nx, ny) || 6 == arr[nx][ny])
		{
			break;
		}
		IsVisited[nx][ny] = true;
		range++;
	}
}
void Check(int x, int y)
{
	int count[4] = { 0,0,0,0 };

	int CurDir = arr[x][y];
	arr[x][y] = 0;
	IsVisited[x][y] = true;
	
	if(5 == CurDir)
	{
		for (int i = 0; i < 4; ++i)
		{
			MakeVisit(x, y, i);
		}	
	}
	else 
	{
		// 각 방향 count 확인 
		for (int i = 0; i < 4; ++i)
		{
			int range = 1;
			while (true)
			{
				int nx = x + dx[i] * range;
				int ny = y + dy[i] * range;
				if (false == InRange(nx, ny) || 6 == arr[nx][ny])
				{
					break;
				}
				if (false == IsVisited[nx][ny])
				{
					count[i]++;
				}
				range++;
			}
		}

		if (1 == CurDir)
		{
			int NexDir = 0;
			int max_count = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (max_count < count[i])
				{
					NexDir = i;
					max_count = count[i];
				}
			}
			MakeVisit(x, y, NexDir);
		}
		else if (2 == CurDir)
		{
			if (count[0] + count[2] > count[1] + count[3])
			{
				MakeVisit(x, y, 0);
				MakeVisit(x, y, 2);
			}
			else
			{
				MakeVisit(x, y, 1);
				MakeVisit(x, y, 3);
			}
		}
		else if (3 == CurDir)
		{
			int NexDir = 0;
			int max_count = 0;
			for (int i = 0; i < 4; ++i)
			{
				if (max_count < count[i] + count[(i+1)%4])
				{
					NexDir = i;
					max_count = count[i] + count[(i + 1) % 4];
				}
			}
			MakeVisit(x, y, NexDir);
			MakeVisit(x, y, (NexDir+1)%4);
		}
		else if (4 == CurDir)
		{
			int NexDir = 0;
			int min_count = m > n ? m : n;
			for (int i = 0; i < 4; ++i)
			{
				if (min_count > count[i])
				{
					NexDir = i;
					min_count = count[i];
				}
			}
			MakeVisit(x, y, (NexDir+1)%4);
			MakeVisit(x, y, (NexDir+2)%4);
			MakeVisit(x, y, (NexDir+3)%4);
		}

	}

	

}

int main()
{
	std::cin >> n >> m;

	arr.resize(n);
	IsVisited.resize(n);
	std::vector<std::vector<std::pair<int, int>>> points;
	points.resize(7);
	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(m);
		IsVisited[i].resize(m);
		for (int j = 0; j < m; ++j)
		{
			std::cin >> arr[i][j];
			if (0 != arr[i][j])
			{
				points[arr[i][j]].push_back(std::make_pair(i, j));
			}
		}
	}
	for (const std::pair<int, int> point : points[5])
	{
		Check(point.first, point.second);
	}
	for (const std::pair<int, int> point : points[4])
	{
		Check(point.first, point.second);
	}
	for (const std::pair<int, int> point : points[2])
	{
		Check(point.first, point.second);
	}
	for (const std::pair<int, int> point : points[3])
	{
		Check(point.first, point.second);
	}
	for (const std::pair<int, int> point : points[1])
	{
		Check(point.first, point.second);
	}



	std::cout << '\n';
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (false == IsVisited[i][j] && 6 != arr[i][j])
			{
				answer++;
				std::cout << 1 << ' ';
			}
			else
			{
				std::cout << 0 << ' ';
			}
		}
		std::cout << '\n';
	}

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
