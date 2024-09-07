// 7569.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

bool InRange(int a, int b, int c, int x, int y, int z)
{
    return 0 <= a && a < x && 0 <= b && b < y && 0 <= c && c < z;
}

int main()
{
    int n, m, h;
    std::cin >> m >> n >> h;
    std::vector<std::vector<std::vector<int>>> box;
	std::queue<std::tuple<int, int, int, int>> q;

    int remaincnt = 0;
    box.resize(h);
    for (int k = 0;k < h;k++)
    {
        box[k].resize(n);
        for (int i = 0;i < n;++i)
        {
            box[k][i].resize(m);
            for (int j = 0;j < m;++j)
            {
                std::cin >> box[k][i][j];
         
                if (0 == box[k][i][j])
                {
                    remaincnt++;
                }
                else if(1 == box[k][i][j])
                {
                    q.push(std::make_tuple(i, j, k, 0));
                }
            }
        }
    }


	const int dx[6] = { 0,0,0,0,1,-1 };
	const int dy[6] = { 0,0,1,-1,0,0 };
	const int dz[6] = { 1,-1,0,0,0,0 };

    int answer = 0;
    while (!q.empty())
    {
		int x, y, z, cnt;
		std::tie(x, y, z, cnt) = q.front();
        q.pop();
        answer = answer > cnt ? answer : cnt;
        for (int i = 0;i < 6;++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (true == InRange(nx, ny, nz, n, m, h) && 0 == box[nz][nx][ny])
            {
                remaincnt--;
                box[nz][nx][ny] = 1;
                q.push(std::make_tuple(nx, ny, nz, cnt + 1));
            }
        }

    }
    if (remaincnt > 0)
    {
        answer = -1;
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
