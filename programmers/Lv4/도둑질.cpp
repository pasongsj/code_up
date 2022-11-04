#include <string>
#include <vector>
#include <iostream>

#define MAX_N 1000001
using namespace std;

int dp0[MAX_N];
int dp1[MAX_N];
int solution(vector<int> money) {

    int index_max = money.size()-1;
    dp0[0] = dp0[1] = money[0];
    dp1[1] = money[1];
    dp1[2] = max(money[1],money[2]);

    for(int i=2;i<index_max;i++){
        dp0[i] = max(dp0[i-1],dp0[i-2]+money[i]);
        dp1[i+1] = max(dp1[i],dp1[i-1]+money[i+1]);
    }
    
    int answer = max(dp0[index_max-1],dp1[index_max]);

    return answer;
}
