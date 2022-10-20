#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> q;
    for(int i=0;i<operations.size();i++){
        stringstream s(operations[i]);
        string oper, num;
        s >> oper >> num;

        if(oper == "I")     q.insert(stoi(num));
        else if(q.empty())  continue;
        else if(num == "1") q.erase(--q.end());
        else                q.erase(q.begin());
    }
    vector<int> answer;
    if(q.empty())   answer.push_back(0),answer.push_back(0);
    else{
        answer.push_back(*(--q.end()));
        answer.push_back(*q.begin());
    }
    return answer;
}
