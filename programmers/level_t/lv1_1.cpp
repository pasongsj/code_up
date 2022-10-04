#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string each_num = to_string(x);
    int tmp = 0;
    for(int i=0;i<each_num.size();i++){
        tmp += each_num[i]-'0';
    }
    if(x%tmp != 0)  return false;
    return answer;
}
