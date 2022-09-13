#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

int coin[MAX_N];
int dp[MAX_M+1];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)    cin >> coin[i];

    for(int i=1;i<=m;i++)   dp[i] = 10001;

    for(int i=1;i<=m;i++){//i원
        for(int j=0;j<n;j++){
            if(i<coin[j])   continue;
            dp[i] = min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[m] == 10001)  cout<<-1;
    else    cout<<dp[m];
    return 0;
}
