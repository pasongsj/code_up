#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b){
    string tmp_a = to_string(a)+to_string(b), tmp_b = to_string(b)+to_string(a);
    return tmp_a > tmp_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),cmp);
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] == 0 && answer == "0")   continue;
	answer+=to_string(numbers[i]);
    }
    return answer;
}
