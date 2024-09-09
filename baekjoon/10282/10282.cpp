// 10282.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, d, c;
        std::cin >> n >> d >> c;
        std::vector<std::vector<std::pair<int,int>>> arr;
		std::vector<int> Isinfected(n + 1, -1);
        arr.resize(n + 1);

        for(int i=0;i<d;++i)
        {
            int a, b, s;
            std::cin >> a >> b >> s;
            arr[b].push_back(std::make_pair(a, s));
        }
        std::queue<std::pair<int,int>> q;
        q.push(std::make_pair(c,0));
        Isinfected[c] = 0;
        while (!q.empty())
        {
            int cur, cur_cnt;
            std::tie(cur, cur_cnt) = q.front();
            q.pop();
            for (std::pair<int,int> next : arr[cur])
            {
                if (-1 == Isinfected[next.first] || Isinfected[next.first] > cur_cnt + next.second)
                {
                    next.second += cur_cnt;
                    Isinfected[next.first] = next.second;
                    q.push(next);
                }
            }
        }
        int cnt = 0;
        int second = 0;
        for (int i = 1;i <= n;++i)
        {
            if (Isinfected[i] == -1)
            {
                continue;
            }
            cnt++;
            second = second > Isinfected[i] ? second : Isinfected[i];
        }
        std::cout << cnt << ' ' << second << '\n';
    }

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
