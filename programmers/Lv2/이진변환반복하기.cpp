#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string to_binary(int n){
    string ans = "";
    while(n>0){
        ans+= to_string(n%2), n/=2;
    }
    return ans;
}

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0), answer.push_back(0);
    while(s.length()>1){
        answer[1] += s.length();
        s.erase(remove(s.begin(),s.end(),'0'),s.end());
        answer[1] -= s.length(); 
        s = to_binary(s.length());
        answer[0]++;
    }
    return answer;
}
