// 13913.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

bool InRange(int a, int m)
{
    return 0 <= a && a <= m;
}


int main()
{
    const int maxnum = 100000;
    std::vector<int> arr(maxnum+1, maxnum+2);
    std::vector<int> lastvisited(maxnum + 1, -1);
    int n, k;
    std::cin >> n >> k;
    arr[n] = 0;

    std::queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if (true == InRange(cur - 1, maxnum) && arr[cur - 1] > arr[cur] + 1)
        {
            arr[cur - 1] = arr[cur] + 1;
            lastvisited[cur - 1] = cur;
            q.push(cur - 1);
        }
        if (true == InRange(cur + 1, maxnum) && arr[cur + 1] > arr[cur] + 1)
        {
            arr[cur + 1] = arr[cur] + 1;
            lastvisited[cur + 1] = cur;
            q.push(cur + 1);
        }
        if (true == InRange(2 * cur, maxnum) && arr[2 * cur] > arr[cur] + 1)
        {
            arr[2 * cur] = arr[cur] + 1;
            lastvisited[2 * cur] = cur;
            q.push(2 * cur);
        }
    }
	std::cout << arr[k] << std::endl;

    std::deque<int> dq;
    while (true)
    {
        dq.push_front(k);
        if (lastvisited[k] == -1)
        {
            break;
        }
        k = lastvisited[k];
    }
    
    for (int ans : dq)
    {
        std::cout << ans << ' ';
    }


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
