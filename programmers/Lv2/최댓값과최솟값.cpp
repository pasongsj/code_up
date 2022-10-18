#include <string>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    
    set<int>nums;
    int num;
    while(ss >> num){  
        nums.insert(num);
    } 

    answer += (to_string(*nums.begin()) + ' ' + to_string(*nums.rbegin()));

    return answer;
}
