#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    auto it = lost.begin();
    while (it != lost.end())
    {
        auto sameit = find(reserve.begin(), reserve.end(), *it);
        if (reserve.end() == sameit)
        {
            it++;
            continue;
        }
        it = lost.erase(it);
        reserve.erase(sameit);
    }

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int cnt = 0, rindex = 0;
    for (int i = 0;i < lost.size();++i)
    {
        while (lost[i] > reserve[rindex] + 1 && rindex < reserve.size())
        {
            rindex++;
        }
        if (rindex == reserve.size())
        {
            break;
        }
        if (abs(lost[i] - reserve[rindex]) <= 1)
        {
            rindex++;
            cnt++;
        }
    }
    answer = n - lost.size() + cnt;
    return answer;
}