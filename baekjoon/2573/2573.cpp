// 2573.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int n, m;

int allcnt;

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,1,-1 };

bool InRange(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Melting(std::vector<std::vector<int>>& arr)
{


    std::vector<std::vector<int>> origin = arr;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 0)
            {
                continue;
            }
            for (int k = 0; k < 4; ++k)
            {
                if (true == InRange(i + dx[k], j + dy[k]) && 0 == origin[i + dx[k]][j + dy[k]])
                {
                    arr[i][j]--;
                    allcnt--;
                    if (0 == arr[i][j])
                    {
                        break;  
                    }
                }
            }
        }
    }
}

#include <queue>
#include <tuple>
int MassCnt(const std::vector<std::vector<int>>& arr)
{
    int cnt = 0;
    std::vector<std::vector<bool>> IsVisited(n, std::vector<bool>(m, false));

    bool isfind = false;
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i)
    {
		for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] != 0)
            {
                isfind = true;
                x = i, y = j;
                i = n;
                break;
            }
        }
    }
    if (-1 == x)
    {
        return cnt;
    }
    std::queue<std::pair<int, int>> q;
    IsVisited[x][y] = true;
    q.push(std::make_pair(x, y));

    while (!q.empty())
    {
        int cx, cy;
        std::tie(cx, cy) = q.front();
        q.pop();
        cnt += arr[cx][cy];
        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (true == InRange(nx, ny) && false == IsVisited[nx][ny] && 0 != arr[nx][ny])
            {
                IsVisited[nx][ny] = true;
                q.push(std::make_pair(nx, ny));
            }
        }
    }
    return cnt;

}


int main()
{
    std::cin >> n >> m;
    std::vector<std::vector<int>> arr;
    
    allcnt = 0;

    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            std::cin >> arr[i][j];
            allcnt += arr[i][j];
        }
    }

    int answer = 0;

    while (true)
    {
        answer++;
        Melting(arr);

        int Check = MassCnt(arr);

        if (Check != allcnt)
        {
            break;  
        }
        else if (Check == allcnt && Check == 0)
        {
            answer = 0;
            break;
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
