#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> wear;
    for(int i=0;i<clothes.size();i++)   wear[clothes[i][1]]++;

    unordered_map<string,int>::iterator it;
    for(it = wear.begin();it!= wear.end();it++){
        answer *= (it->second + 1);
    }
    answer--;
    return answer;
}

