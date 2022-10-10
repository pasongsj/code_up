#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int a=0;a<commands.size();a++){
        int i = commands[a][0],j = commands[a][1],k = commands[a][2];
        vector<int> tmp = vector<int>(array.begin()+ i-1,array.begin() + j);
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}
