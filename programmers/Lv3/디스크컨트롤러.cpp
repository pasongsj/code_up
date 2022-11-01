#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>> q;
    
    sort(jobs.begin(),jobs.end());    
    int index = 0;
    vector<int> tmp = jobs[index++];
    int now = tmp[0];

    q.push(make_pair(-tmp[1],tmp[0]));
    
    
    while(q.size()>0){
        
        int s,e;
        tie(e,s) = q.top();
        now = max(now,s) - e;
        answer += (now-s);
        q.pop();
        
        while(index<jobs.size() && (q.empty() || jobs[index][0]<=now)){
            tmp = jobs[index++];
            q.push(make_pair(-tmp[1],tmp[0]));
        }
        
    }
    return answer/jobs.size();
}
