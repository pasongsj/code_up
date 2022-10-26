#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> ans;
string arr;

bool cmp(string a, string b){
    if(a.size() != b.size())    return false;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i] || b[i] == '*') continue;
        return false;
    }
    return true;
}

void dfs(vector<string> user_id, vector<string> banned_id, int index){
    if(index == banned_id.size()){
        string tmp = arr;
        sort(tmp.begin(),tmp.end());
        ans.insert(tmp);
        return;
    }
    for(int i=0;i<user_id.size();i++){
        if(cmp(user_id[i], banned_id[index])&&
          (arr.size() == 0 || arr.find(to_string(i)) == string::npos)){
            arr+= to_string(i);
            dfs(user_id, banned_id,index+1);
            arr.erase(arr.size()-1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id, banned_id,0);
    answer = ans.size();
    return answer;
}

