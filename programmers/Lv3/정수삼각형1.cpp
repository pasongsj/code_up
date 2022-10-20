#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp = {triangle[0]};
    
    for(int i=1;i<triangle.size();i++){
        vector<int> line;
        for(int j=0;j<triangle[i].size();j++){
            int tmp = triangle[i][j];
            if(j == 0)  tmp += dp[i-1][j];
            else if(j == triangle[i].size()-1)  tmp+=dp[i-1][j-1];
            else tmp += max(dp[i-1][j],dp[i-1][j-1]);
            line.push_back(tmp);
        }
       dp.push_back(line);
    }
    int index = triangle.size()-1;
    for(int i=0;i<triangle[index].size();i++)    answer = max(answer,dp[index][i]);
    return answer;
}
