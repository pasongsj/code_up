#include <string>
#include <vector>
#define MAX_N 2001
using namespace std;

long long solution(int n) {
    long long dp[MAX_N] = {0};
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%1234567;
    }
    long long answer = dp[n];
    return answer;
}
