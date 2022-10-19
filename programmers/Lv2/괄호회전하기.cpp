#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

bool is_col(string rot){
    unordered_map<char,char> match = {{']','['}, {')','('}, {'}','{'}};
    stack<char> stack;
    for(int i=0;i<rot.size();i++){
        if((rot[i] == ']'|| rot[i] == ')' || rot[i] == '}')){
            if(stack.size() == 0)   return false;
            else if(stack.top() == match[rot[i]])    stack.pop();
        }
        else    stack.push(rot[i]);
    }
    if(stack.size()>0)  return false;
    return true;
     
}
int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        rotate(s.begin(),s.begin()+1,s.end());
        if(is_col(s)) answer++;
    }
    return answer;
}
