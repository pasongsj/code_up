#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int findParent(int num)
{
    while (arr[num] != num)
    {
        num = arr[num];
    }
    return num;
}

void changeParent(int root, int dest)
{
    if (arr[dest] != dest)
    {
        changeParent(root, arr[dest]);
    }
    arr[dest] = root;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);
    for (vector<int> cost : costs)
    {
        int from = cost[0];
        int to = cost[1];
        int curcost = cost[2];
        ///
        if (findParent(to) == findParent(from))
        {
            continue;
        }
        else
        {
            changeParent(findParent(from), to);
            answer += curcost;
        }

    }
    return answer;
}