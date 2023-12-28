#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>


using namespace std;
std::vector<std::vector<int>> alloil;

int n;
int m;

const int nx[4] = { 0,0,1,-1 };
const int ny[4] = { 1,-1,0,0 };

bool in_range(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y, std::vector<std::vector<bool>>& ischecked,
    const std::vector<std::vector<int>>& Land)
{
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));
    ischecked[x][y] = true;
    std::set<int> allM;
    int cnt = 0;
    while (!q.empty())
    {
        int cx, cy;
        std::tie(cx, cy) = q.front();
        q.pop();
        allM.insert(cy);
        cnt++;
        for (int i = 0; i < 4; ++i)
        {
            int nextX = cx + nx[i];
            int nextY = cy + ny[i];
            if (true == in_range(nextX, nextY) && false == ischecked[nextX][nextY] &&
                1 == Land[nextX][nextY])
            {
                q.push(std::make_pair(nextX, nextY));
                ischecked[nextX][nextY] = true;
            }
        }
    }
    for (int num : allM)
    {
        alloil[num].push_back(cnt);
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    std::vector<std::vector<bool>> ischecked(n, vector<bool>(m, false));
    alloil.resize(m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (false == ischecked[i][j] && 1 == land[i][j])
            {
                dfs(i, j, ischecked, land);
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int tmp = 0;
        for (int j = 0; j < alloil[i].size(); ++j)
        {
            tmp += alloil[i][j];
        }
        answer = answer > tmp ? answer : tmp;
    }
    return answer;
}