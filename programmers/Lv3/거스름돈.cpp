#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    std::vector<int> dp;
    dp.resize(n + 1);
    dp[0] = 1;
    for (int curval : money)
    {
        for (int i = curval; i <= n;++i)
        {
            dp[i] += dp[i - curval];
        }
    }
    answer = dp[n];
    return answer;
}
