// 1987.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>

int answer;

std::map<int, int> isvisitmap;

bool InRange(int x, int y, int n, int m)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int cx, int cy, const std::vector<std::vector<char>>& arr, int cnt)
{
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};


    answer =  std::max(answer,cnt);
    

    for (int i = 0; i < 4; ++i)
    {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (true == InRange(nx, ny, arr.size(), arr[0].size()))
        {
            if (isvisitmap[arr[nx][ny]] != 1)
            {
                isvisitmap[arr[nx][ny]] = 1;
                dfs(nx, ny, arr, cnt + 1);
                isvisitmap[arr[nx][ny]] = 0;
            }
        }
    }
}

int main()
{
    std::vector<std::vector<char>> arr;

    int r, c;
    std::cin >> r >> c;
    arr.resize(r);
    for (int i = 0; i < r; ++i)
    {
        arr[i].resize(c);
        for (int j = 0; j < c; ++j)
        {
            std::cin >> arr[i][j];
        }
    }
    answer = 0;
    isvisitmap[arr[0][0]] = 1;
	dfs(0, 0, arr, 1);
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
