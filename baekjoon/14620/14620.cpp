// 14620.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int answer;

bool InRange(int a, int b, int n)
{
    return 0 <= a - 1 && a + 1 < n && 0 <= b - 1 && b + 1 < n;
}

bool CanPlant(int a, int b, const std::vector<std::vector<bool>>& _isplanted)
{
    if (false == InRange(a, b, _isplanted.size()) || true == _isplanted[a][b])
    {
        return false;
    }
    for (int i = 0;i < 4;++i)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if (false == _isplanted[nx][ny])
        {
            continue;
        }
		return false;
    }
    return true;
}

int GetCount(const std::vector<std::vector<int>>& ground, const std::vector<std::vector<bool>>& plant)
{
    int n = ground.size();
    int cnt = 0;
    for (int i = 0;i < n;++i)
    {
        for (int j = 0;j < n;++j)
        {
            if (true == plant[i][j])
            {
                cnt += ground[i][j];
            }
        }
    }
    return cnt;
}

void DFS(int index, int cnt,const std::vector<std::vector<int>>& _ground,std::vector<std::vector<bool>>& _isplanted)
{
    if (cnt == 3)
    {
        int curcount = GetCount(_ground,_isplanted);
        answer = answer < curcount ? answer : curcount;
        return;
    }
    int n = _ground.size();
    if (index == n * n)
    {
        return;
    }

    int a = index / n;
    int b = index % n;
    if (true == CanPlant(a, b, _isplanted))
    {
        int nx = a, ny = b;
        _isplanted[a][b] = true;
        for (int i = 0;i < 4;++i)
        {
            nx = a + dx[i];
            ny = b + dy[i];
            _isplanted[nx][ny] = true;
            
        }
        DFS(index + 1, cnt + 1, _ground, _isplanted);

        _isplanted[a][b] = false;
        for (int i = 0;i < 4;++i)
        {
            nx = a + dx[i];
            ny = b + dy[i];
            _isplanted[nx][ny] = false;
        }
    }
    DFS(index + 1, cnt, _ground, _isplanted);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> ground;
    std::vector<std::vector<bool>> isplanted;

    ground.resize(n);
    isplanted.resize(n);
    for (int i = 0;i < n;++i)
    {
        ground[i].resize(n);
        isplanted[i].resize(n);
        for (int j = 0;j < n;++j)
        {
            std::cin >> ground[i][j];
            isplanted[i][j] = false;
        }
    }
    answer = n*n*200;
    DFS(0,0, ground,isplanted);
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
