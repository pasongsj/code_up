// 15681.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

std::vector<bool> isvisited;
std::vector<int> res;

int DFS(int q, const std::vector<std::vector<int>>& links)
{
    int cnt = 1;
    for (int i = 0; i < links[q].size(); ++i)
    {
        int next = links[q][i];
        if (false == isvisited[next])
        {
            isvisited[next] = true;
            cnt += DFS(next, links);
        }
    }

    res[q] = cnt;
    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, R, Q;
    std::cin >> N >> R >> Q;

    isvisited.resize(N + 1);
    res.resize(N + 1);

    std::vector<std::vector<int>> links(N + 1, std::vector<int>());
    for (int i = 0; i < N - 1; ++i)
    {
        int U, V;
        std::cin >> U >> V;
        links[U].push_back(V);
        links[V].push_back(U);
    }

    isvisited[R] = true;
    DFS(R, links);

    for (int i = 0; i < Q; ++i)
    {
        int num;
        std::cin >> num;
        std::cout << res[num] << '\n';
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
