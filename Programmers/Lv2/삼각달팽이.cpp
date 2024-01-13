#include <string>
#include <vector>

using namespace std;
std::vector<std::vector<int>> arr;

const int dx[3] = { 1,0,-1 };
const int dy[3] = { 0,1,-1 };


bool in_range(int x, int y)
{
    return 0 <= x && x < arr.size() && 0 <= y && y < arr[x].size();
}

vector<int> solution(int n) {
    vector<int> answer;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].resize(i + 1);
    }

    int number = 1;
    int dir = 0;
    int cx = 0, cy = 0;
    arr[cx][cy] = number++;
    while (true)
    {
        if (false == in_range(cx + dx[dir], cy + dy[dir]) || arr[cx + dx[dir]][cy + dy[dir]] != 0)
        {
            dir = (dir + 1) % 3;
        }

        if (arr[cx + dx[dir]][cy + dy[dir]] != 0)
        {
            break;
        }
        cx += dx[dir];
        cy += dy[dir];
        arr[cx][cy] = number++;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}