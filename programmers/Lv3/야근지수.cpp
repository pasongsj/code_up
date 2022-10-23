#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> q(works.begin(), works.end());
    
    while(n--){
        int tmp = q.top();
        if(tmp<=0)  break;
        q.pop();
        q.push(tmp-1);
    }
    long long answer = 0;
    while(!q.empty()){
        answer+= q.top() * q.top();
        q.pop();
    }
    return answer;
}
