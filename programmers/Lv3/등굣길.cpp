#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    bool cant_go[101][101] = {false};
    //길 체크
    for(int i=0;i<puddles.size();i++){
        cant_go[puddles[i][1]-1][puddles[i][0]-1] = true;
    }
    
    long long dp[101][101] = {0};
    dp[0][0] = 1;
    //init
    for(int i=1;i<n;i++){
        if(!cant_go[i][0])    dp[i][0] = dp[i-1][0];
        else    dp[i][0] = 0;
    }
    for(int i=1;i<m;i++){
        if(!cant_go[0][i])    dp[0][i] = dp[0][i-1];
        else    dp[0][i] = 0;
    }
    //dp
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!cant_go[i][j])    dp[i][j] = (dp[i-1][j]+dp[i][j-1])%1000000007;
            else    dp[i][j] = 0;
        }
    }
    answer = dp[n-1][m-1];
    
    return answer;
}
