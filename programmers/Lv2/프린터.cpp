#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pri;
    for(int i=0;i<priorities.size();i++){
        pri.push(priorities[i]);
    }
    
    int index = 0;
    int last_index = priorities.size();
    while(!pri.empty()){
        int tmp = priorities[index];//현재 loc
        if(pri.top() == tmp){
            pri.pop();
            answer++;
            if(location == index)   break;
        }
        else{
            priorities.push_back(tmp);
            if(index == location)  location = last_index;
            last_index++;
        }
        index++;
    }
    return answer;
}
