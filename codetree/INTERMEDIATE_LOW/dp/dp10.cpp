#include <iostream>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;
#define MAX_N 100
#define MAX_M 10000

pair<int,int> jewel[MAX_N+1];

set<int> bag[MAX_M+1];
int dp[MAX_M+1];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int w,v;
        cin >> w >> v;
        jewel[i] = make_pair(w,v);
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            int w,v;
            tie(w,v) = jewel[j];
            if(w > i || dp[i] > dp[i-w] + v) continue;
            if(!bag[i-w].empty() && bag[i-w].find(j) != bag[i-w].end()) continue;
            dp[i] = dp[i-w] + v;
            bag[i] = bag[i-w];
            bag[i].insert(j);
        }
        if(dp[i]<dp[i-1]){
            dp[i] = dp[i-1];
            bag[i] = bag[i-1];
        }
    }
    cout<<dp[m];
    return 0;
}
