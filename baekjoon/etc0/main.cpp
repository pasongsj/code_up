#include <iostream>
#include <vector>


const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int answer;

bool InRange(int x, int y, int n, int m)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int cx, int cy, std::vector<std::vector<int>>& maps, std::vector<std::vector<bool>>& isvisted, int dir)
{
    if (maps[cx][cy] == 1)
    {
        maps[cx][cy] = 0;
        answer++;
    }
    if (dir == -1)
    {
        for (int i = 0;i < 4;++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (true == InRange(nx, ny, maps.size(), maps[0].size()) && false == isvisted[nx][ny] && 2 != maps[nx][ny])
            {
                 dfs(nx, ny, maps, isvisted, i);
            }
        }
    }
    else
    {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (true == InRange(nx, ny, maps.size(), maps[0].size()) && false == isvisted[nx][ny])
        {
            if (2 == maps[nx][ny])
            {
                isvisted[cx][cy] = true;
                dfs( cx, cy, maps, isvisted, -1);
            }
            else
            {
                dfs( nx, ny, maps, isvisted, dir);
            }
        }
    }

}
int main()
{
	std::vector<std::vector<int>>maps = { {2, 2, 2, 2, 2, 1, 2, 2},
        {2, 2, 1, 0, 0, 0, 1, 2},
        {2, 2, 2, 0, 0, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 2, 2},
        {2, 0, 2, 0, 1, 0, 1, 0},
        {2, 1, 0, 0, 0, 0, 2, 2},
        {2, 2, 2, 2, 2, 1, 2, 2} };

    int startx = 3, starty = 3;
    int n = maps.size();
    int m = maps[0].size();

    answer = 0;

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    dfs(startx, starty, maps, visited, -1);
    std::cout << answer;

    return 0;

}