#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    if(arr1[0].size() != arr2.size()){
        vector<vector<int>> tmp = arr1;
        arr1 = arr2;
        arr2 = tmp;
    }

    for(int i=0;i<arr1.size();i++){
        vector<int>temp;
        for(int k=0;k<arr2[0].size();k++){
            int num = 0;
            for(int j=0;j<arr1[0].size();j++){
                num += arr1[i][j]*arr2[j][k];
            }
            temp.push_back(num);
        }
        answer.push_back(temp);
    }
    return answer;
}

