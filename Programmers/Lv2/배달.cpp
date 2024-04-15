#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
using namespace std;

void Dijk(std::vector<int>& Dist, const std::vector<std::vector<int>> graph, int N)
{

}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, INT_MAX / 2));
    for (const std::vector<int>& info : road)
    {
        if (graph[info[0]][info[1]] > info[2])
        {
            graph[info[0]][info[1]] = info[2];
            graph[info[1]][info[0]] = info[2];
        }

    }
    for (int i = 1; i <= N; ++i)
    {
        graph[i][i] = 0;
    }

    std::vector<int> Dist(N + 1, INT_MAX / 2);
    //dijk

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<std::pair<int, int>>> pq;//cost, node;
    for (int i = 1; i <= N; ++i)
    {
        pq.push(std::make_pair(graph[1][i], i));
    }

    while (!pq.empty())
    {
        int curnode, curcost;
        std::tie(curcost, curnode) = pq.top();
        pq.pop();
        for (int next = 1; next <= N; ++next)
        {
            if (Dist[next] > curcost + graph[curnode][next])
            {
                Dist[next] = curcost + graph[curnode][next];
                pq.push(std::make_pair(Dist[next], next));
            }
        }
    }



    for (int i = 1; i <= N; ++i)
    {
        if (Dist[i] <= K)
        {
            answer++;
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}