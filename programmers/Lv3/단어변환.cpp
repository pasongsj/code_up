#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>arr;
int ans = 51;
bool cmp(string a, string b){
    int diff = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] !=b[i]) diff++;
    }
    if(diff == 1) return true;
    return false;
}

void bfs(string now, string tar, vector<string> w){
    if(now == tar){
        ans = min(ans, (int)arr.size());
        return;
    }
    if(arr.size() == w.size())  return;
    for(int i=0;i<w.size();i++){
        if(find(arr.begin(),arr.end(),i) != arr.end())    continue;
        if(cmp(now,w[i])){
            arr.push_back(i);
            bfs(w[i],tar,w);
            arr.pop_back();
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> ch;
    bfs(begin,target,words);
    answer = ans;
    if(answer == 51)    return 0;
    return answer;
}
