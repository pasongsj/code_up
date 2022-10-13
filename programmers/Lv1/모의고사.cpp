#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> cnt(3);
    int num[3] = {5,8,10};
    int person1[5] = {1, 2, 3, 4, 5} , person2[8] = {2, 1, 2, 3, 2, 4, 2, 5}, person3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i=0;i<answers.size();i++){
        if(person1[i%num[0]] == answers[i]) cnt[0]++;
        if(person2[i%num[1]] == answers[i])  cnt[1]++;
        if(person3[i%num[2]] == answers[i])  cnt[2]++;
    }
    int max_ans = 0;
    vector<int> ans;
    for(int i=0;i<3;i++){
        if(max_ans > cnt[i]) continue;
        if(max_ans<cnt[i])  ans.clear();
        ans.push_back(i+1);
        max_ans = cnt[i];
    }
    return ans;
}
