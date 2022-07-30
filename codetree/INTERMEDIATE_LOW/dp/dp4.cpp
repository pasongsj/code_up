#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100
int arr[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n;

void init_dp(){
    dp[0][0] = arr[0][0];
    for(int i=1;i<n;i++){
        dp[i][0] = min(dp[i-1][0],arr[i][0]);
        dp[0][i] = min(dp[0][i-1],arr[0][i]);
    }
}
void dp_fun(){
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(min(arr[i][j],dp[i-1][j]),min(arr[i][j],dp[i][j-1]));
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            dp[i][j] = INT_MIN;
        }
    }
    init_dp();
    dp_fun();
    
    cout<<dp[n-1][n-1];
    return 0;
}
