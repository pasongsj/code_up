#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int dfs(const std::vector<int>& ignore, const std::vector<std::vector<int>>& arr)
{
    std::set<int> visited;
    std::queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < arr[cur].size(); ++i)
        {

            if (ignore[0] == cur && ignore[1] == arr[cur][i] ||
                ignore[0] == arr[cur][i] && ignore[1] == cur)
            {
                continue;
            }
            if (visited.end() == visited.find(arr[cur][i]))
            {
                visited.insert(arr[cur][i]);
                q.push(arr[cur][i]);
            }
        }
    }
    return static_cast<int>(visited.size());
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n - 1;


    std::vector<std::vector<int>> arr;
    arr.resize(n + 1);
    for (std::vector<int> n : wires)
    {
        arr[n[0]].push_back(n[1]);
        arr[n[1]].push_back(n[0]);
    }

    for (std::vector<int> wire : wires)
    {
        int diff = dfs(wire, arr);
        diff = abs(2 * diff - n);
        answer = answer > diff ? diff : answer;
    }


    return answer;

}
