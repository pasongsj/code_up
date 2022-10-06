#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int before;
    for(int i=0;i<progresses.size();i++){  
        int days =(100-progresses[i]+(speeds[i]-1))/speeds[i];
        if(i == 0 || before < days){
            answer.push_back(1);
            before = days;
        }
        else    answer.back()++;
    }
    return answer;
}
