// 8972.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

int n, m;
std::vector<std::vector<char>> arr;
std::vector<std::vector<char>> tmparr;

std::pair<int, int> NexPos(std::pair<int, int>cur, std::pair<int, int> dest)
{
    int nx = dest.first - cur.first;
    int ny = dest.second - cur.second;
    if (0 != nx)
    {
        nx /= abs(nx);
    }
    if (0 != ny)
    {
        ny /= abs(ny);
    }
    cur.first += nx;
    cur.second += ny;
    return cur;
}
void CpyArr()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = tmparr[i][j];
            if ('B' == arr[i][j])
            {
                arr[i][j] = '.';
            }
            tmparr[i][j] = '.';
        }
    }

}

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}


bool MoveNext(std::pair<int, int>& _cur, int dir)
{
    const int dx[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
    const int dy[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };

    _cur.first += dx[dir];
    _cur.second += dy[dir];
    tmparr[_cur.first][_cur.second] = 'I';

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ('R' == arr[i][j])
            {
                std::pair<int,int> nPos = NexPos(std::make_pair(i, j), _cur);
                if ('R' == tmparr[nPos.first][nPos.second] || 'B' == tmparr[nPos.first][nPos.second])
                {
                    tmparr[nPos.first][nPos.second] = 'B';
                }
                else if ('I' == tmparr[nPos.first][nPos.second])
                {
                    return false;
                }
                else
                {
                    tmparr[nPos.first][nPos.second] = 'R';
                }
            }
        }
    }

    CpyArr();
    return true;
}

int main()
{
    // 입력

	std::cin >> n >> m;
    arr.resize(n);
    tmparr.resize(n);
    std::pair<int, int> curI;
    for (int i = 0; i < n; ++i)
    {
        arr[i].resize(m);
        tmparr[i].resize(m);
        for (int j = 0; j< m; ++j)
        {
            std::cin >> arr[i][j];
            if ('I' == arr[i][j])
            {
                curI = std::make_pair(i, j);
            }
            tmparr[i][j] = '.';
        }
    }



    std::string moving;
    std::cin >> moving;


    for (int i = 0; i < moving.size(); ++i)
    {
        if (false == MoveNext(curI, moving[i] - '0'))
        {
            std::cout << "kraj " << i + 1;
            return 0;
        }
    }

	Print();

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
