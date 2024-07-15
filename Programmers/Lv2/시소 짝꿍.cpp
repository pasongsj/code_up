#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    std::map<int, long long> allmaps;
    for (int wei : weights)
    {
        allmaps[wei]++;
    }

    for (const std::pair<int, int>& map : allmaps)
    {
        int curwei = map.first;
        long long cnt = map.second;
        if (map.second > 1)
        {
            answer += cnt * (cnt - 1) / 2;
        }
        if (allmaps.end() != allmaps.find(map.first * 2))
        {
            answer += cnt * allmaps[map.first * 2];
        }
        if (map.first % 2 == 0 && allmaps.end() != allmaps.find(map.first / 2 * 3))
        {
            answer += cnt * allmaps[map.first / 2 * 3];
        }
        if (map.first % 3 == 0 && allmaps.end() != allmaps.find(map.first / 3 * 4))
        {
            answer += cnt * allmaps[map.first / 3 * 4];
        }
    }

    // 1 : 1
    // 1 : 2
    // 2 : 3
    // 3 : 4

    return answer;
}