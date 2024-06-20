#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    std::map<int, int> oran;
    for (int t : tangerine)
    {
        oran[t]++;
    }

    std::vector<std::pair<int, int>> sortedoran;
    for (const std::pair<int, int> p : oran)
    {
        sortedoran.push_back(std::make_pair(p.second, p.first));
    }

    std::sort(sortedoran.begin(), sortedoran.end(), std::greater<std::pair<int, int>>());
    int cnt = 0, i = 0;
    for (; i < sortedoran.size(); ++i)
    {
        cnt += sortedoran[i].first;
        if (cnt >= k)
        {
            break;
        }
    }
    answer = ++i;
    return answer;
}