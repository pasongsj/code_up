#include <iostream>
using namespace std;
#define MAX_N 1001

int dp[MAX_N];
int main(){
    int n;
    cin >> n;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<=n;i++){
        dp[i] = (dp[i-2] + dp[i-3])%10007;

    }
    cout<<dp[n];
    return 0;
}

