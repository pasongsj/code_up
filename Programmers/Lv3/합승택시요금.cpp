#include <string>
#include <vector>
#include <climits>

using namespace std;
int min(int a, int b)
{
    return a > b ? b : a;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    std::vector<std::vector<int>> dist;
    dist.resize(n + 1);

    std::vector<bool> visited(false, n + 1);

    for (int i = 0; i < n + 1; ++i)
    {
        dist[i].resize(n + 1);
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 100000 * 200;
        }
    }

    for (int i = 0; i < fares.size(); ++i)
    {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    int answer = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int sum = dist[s][i] + dist[i][a] + dist[i][b];
        answer = answer > sum ? sum : answer;
    }
    return answer;
}