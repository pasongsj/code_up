#include <string>
#include <vector>
using namespace std;

int cal(vector<int>num, int index, int res,int tar){
    if(index == num.size()){
        if(res == tar)  return 1;
        else    return 0;
    }
    return cal(num, index+1, res+num[index],tar) + cal(num, index+1, res-num[index],tar);
    
}
int solution(vector<int> numbers, int target) {
    int answer = cal(numbers,0,0,target);
    return answer;
}
