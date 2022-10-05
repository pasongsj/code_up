#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a.length() < b.length();
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> cache;
    sort(phone_book.begin(),phone_book.end(),cmp);
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=1;j<=phone_book[i].size();j++){
            if(cache.find(phone_book[i].substr(0, j)) != cache.end())   return false;
        }
        cache.insert(phone_book[i]);
    }
    return answer;
}
