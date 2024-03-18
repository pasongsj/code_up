// 14658.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <set>


std::map<int, std::set<int>> stars;

int GetMax(int x, int y, int l)
{
    int cnt = 0;
    auto it_i = stars.find(x);
    while (it_i!= stars.end() && it_i->first <= x + l)
    {
        auto it_j = it_i->second.lower_bound(y);
		while (it_j != it_i->second.end() && *it_j <= y + l)
        {
            cnt++;
            it_j++;
        }
        it_i++;
    }
    return cnt;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, m, l, k;
    std::cin >> n >> m >> l >> k;


    std::set<int> Xlist;
    std::set<int> Ylist;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        stars[x].insert(y);
        Xlist.insert(x);
        Ylist.insert(y);
    }

    int ans = 0;

    for (int i : Xlist)
    {
        for (int j : Ylist)
        {
            int cur = GetMax(i, j, l);
            ans = std::max(ans, cur);
        }
    }

    std::cout << k - ans;
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
