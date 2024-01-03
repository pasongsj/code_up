#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

// 오른쪽방향
// 아래방향
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

bool InRange(int x, int y, int n)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

//  0    1    2    3
//  동   서   남    북
int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    std::vector<std::vector<std::map<int, int>>> dp;
    std::vector<std::vector<bool>> is_visited;

    int n = board.size();

    dp.resize(n);
    is_visited.resize(n);

    for (int i = 0; i < n; ++i)
    {
        dp[i].resize(n);
        is_visited[i].resize(n);
    }

    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));
    is_visited[0][0] = true;

    for (int i = 0; i < 4; ++i)
    {
        dp[0][0][i] = 100;
    }

    while (!q.empty())
    {
        int x, y;
        std::tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (true == InRange(nx, ny, n) && false == is_visited[nx][ny] && 0 == board[nx][ny])
            {
                q.push(std::make_pair(nx, ny));
                is_visited[nx][ny] = true;
                if (x == 1 && y == 1)
                {
                    int a = 0;
                }

                // i 는 방향
                int rescost = INT_MAX;
                for (int k = 0; k < 4; ++k)
                {
                    if (dp[x][y][k] == 0)
                    {
                        continue;
                    }
                    int cost = dp[x][y][k] + 100;
                    if (i != k)
                    {
                        cost += 400;
                    }
                    if(rescost)
                    rescost = rescost > cost ? cost : rescost;
                }

            }
        }
    }

    for (const std::pair<int, int> _pair : dp[2][2])
    {
        std::cout << _pair.second << '\n';
        answer = answer > _pair.second ? _pair.second : answer;
    }



    return answer;
}

// 0은 이동가능
// 1은 이동 불가능

// [0, 0, 0, 0, 0],
// [0, 1, 1, 1, 0],
// [0, 0, 1, 0, 0],
// [1, 0, 0, 0, 1],
// [1, 1, 1, 0, 0]]

int main()
{
    //solution({ {0, 0, 0}, {0, 0, 0}, {0, 0, 0} });
   //solution({ {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0} });
    solution({ {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0} });
   //solution({ {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0} });
    return 0;
}