#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
// 북, 동, 남, 서
int solution(vector<vector<int>> board) {
    int N = board.size();
    std::vector<std::vector<std::vector<bool>>> visited(4, std::vector<std::vector<bool>>(N, std::vector<bool>(N, false)));
    std::vector<std::vector<std::vector<int>>> costs(4, std::vector<std::vector<int>>(N, std::vector<int>(N, INT32_MAX)));

    std::queue<tuple<int, int, int>> q;
    // 동, 남
    for (int d = 1; d <= 2; d++) {
        q.emplace(0, 0, d);
        costs[d][0][0] = 0;
    }

    while (!q.empty()) {
        int x, y, d;
        std::tie(x, y, d) = q.front();
        q.pop();

        for (int nd = 0; nd < 4; nd++) {
            int nx = x + dx[nd], ny = y + dy[nd];

            int nextcost = costs[d][x][y] + (nd == d ? 100 : 600);

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != 0 || nextcost >= costs[nd][nx][ny])
                continue;

            costs[nd][nx][ny] = nextcost;
            q.push(std::make_tuple(nx, ny, nd));
        }
    }

    int answer = INT32_MAX;
    for (const auto& cost : costs) {
        answer = min(answer, cost[N - 1][N - 1]);
    }
    return answer;
}