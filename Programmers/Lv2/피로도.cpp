#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GetDunCount(const std::vector<std::vector<int>>& dung, const std::vector<int>& order, int k)
{
    int ans = 0;
    for (int num : order)
    {
        if (dung[num][0] > k)
        {
            continue;
        }
        k -= dung[num][1];
        ans++;
    }
    return ans;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    std::vector<int> curvec;
    for (int i = 0; i < dungeons.size(); ++i)
    {
        curvec.push_back(i);
    }

    do {
        answer = std::max(answer, GetDunCount(dungeons, curvec,k));
    } while (next_permutation(curvec.begin(), curvec.end()));

    return answer;
}