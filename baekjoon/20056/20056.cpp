// 20056.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>


int main()
{
	int n, m, T;
	std::cin >> n >> m >> T;

	std::vector<std::vector<std::vector<std::tuple<int, int, int>>>> arr(n , std::vector<std::vector<std::tuple<int, int, int>>>(n , std::vector<std::tuple<int, int, int>>()));
	std::vector<std::vector<std::vector<std::tuple<int, int, int>>>> nextvec(n, std::vector<std::vector<std::tuple<int, int, int>>>(n , std::vector<std::tuple<int, int, int>>()));


	for (int i = 0; i < m; ++i)
	{
		int r, c, m, s, d;
		std::cin >> r >> c >> m >> s >> d;
		r--;
		c--;
		arr[r][c].push_back(std::make_tuple(m, s, d));
	}

	const int dx[8] = { -1,	-1,	0,	1,	1,	1,	0,	-1};
	const int dy[8] = {	0,	1,	1,	1,	0,	-1,	-1,	-1};
	while (T--)
	{
		// 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < arr[i][j].size(); ++k)
				{
					int m, s, d;
					std::tie(m, s, d) = arr[i][j][k];
					int nx = i + dx[d] * s;
					int ny = j + dy[d] * s;
					{
						nx = (nx + n * (abs(nx) / n + 1)) % n;
						ny = (ny + n * (abs(ny) / n + 1)) % n;
						nextvec[nx][ny].push_back(arr[i][j][k]);
					}

				}
				arr[i][j].clear();
			}
		}

		// 2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸 처리

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (nextvec[i][j].size() == 1)
				{
					arr[i][j].push_back(nextvec[i][j][0]);
				}
				else if(nextvec[i][j].size() > 0)
				{
					int m = 0, s = 0;
					bool d = 0;//
					for (int l = 0; l < nextvec[i][j].size(); ++l)
					{
						int n_m, n_s, n_d;
						std::tie(n_m, n_s, n_d) = nextvec[i][j][l];
						m += n_m;;
						s += n_s;
						if (d == 1 || l == 0)
						{
							continue;
						}
						if (n_d % 2 != std::get<2>(nextvec[i][j][l - 1]) % 2)
						{
							d = 1;
						}
					}
					m /= 5;
					if (m > 0)
					{
						s /= nextvec[i][j].size();
						for (int dir = 0; dir < 8; dir += 2)
						{
							arr[i][j].push_back(std::make_tuple(m, s, dir + d));
						}
					}
				}
				nextvec[i][j].clear();
			}
		}
	}


	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < arr[i][j].size(); ++k)
			{
				int m, s, d;
				std::tie(m, s, d) = arr[i][j][k];
				answer += m;
			}
		}
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
