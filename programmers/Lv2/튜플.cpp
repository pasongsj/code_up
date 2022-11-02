#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp;
    unordered_map<int,int> num;
    for(char i:s){
        if((i == ','||i =='}')&&tmp.length()>0){
            num[stoi(tmp)]++;
            tmp = "";
        }
        else if(i == '{' || i == '}')   tmp = "";
        else    tmp+=i;
    }
    vector<pair<int,int>> list(num.begin(),num.end());
    sort(list.begin(),list.end(),cmp);
    for(auto j:list)    answer.push_back(j.first);
    return answer;
}
