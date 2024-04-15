// 13424.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <tuple>
int n;


int dijkstra(int start, const std::vector<std::vector<int>>& _graph, const std::vector<int>& _friends)
{
    std::vector<int> Dist;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    Dist.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        Dist[i] = _graph[start][i];
        pq.push(std::make_pair(Dist[i], i));
        if (i == start)
        {
            Dist[i] = 0;
        }
    }
    while (!pq.empty())
    {
        int cur, cost;
        std::tie(cost, cur) = pq.top();
        pq.pop();
        if (Dist[cur] < cost) continue;
        for (int j = 1; j <= n; ++j)
        {
            if (cost + _graph[cur][j] < Dist[j])
            {
                Dist[j] = cost + _graph[cur][j];
                pq.push(std::make_pair(Dist[j], j));
            }
        }
    }
    int result = 0;
    for (int _fri : _friends)
    {
        result += Dist[_fri];
    }
    return result;
}

int main()
{
    int t, m, k;
    std::cin >> t;
    std::vector<int> answer;


    while (t--)
    {
        std::cin >> n >> m;
        std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, INT_MAX/2));

        for (int i = 0; i < m; ++i)
        {
            int a, b, c;
            std::cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }
        for (int i = 1; i <= n; ++i)
        {
            graph[i][i] = 0;
        }

        std::cin >> k;
        std::vector<int> friends;
        friends.resize(k);
        for (int j = 0; j < k; ++j)
        {
            std::cin >> friends[j];
        }

        int cur_min = INT_MAX;
        int index = -1;
        for (int i = 1; i <= n; ++i)
        {
            int next_dij = dijkstra(i, graph, friends);
            if (cur_min > next_dij)
            {
                index = i;
                cur_min = next_dij;
            }
        }
        answer.push_back(index);
    }
    for (int ans : answer)
    {
        std::cout << ans << '\n';
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
