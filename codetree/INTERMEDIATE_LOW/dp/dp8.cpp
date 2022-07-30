#include <iostream>
#include <climits>
using namespace std;
int s[1001];
int e[1001];
int p[1001];
int dp[1001];// endtime, pay
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i] >> e[i] >> p[i];
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
       // dp[i].first = e[i];
        for(int j=0;j<i;j++){
            if(e[j]<s[i]){
                dp[i] = max(dp[j]+p[i],dp[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
    
}
