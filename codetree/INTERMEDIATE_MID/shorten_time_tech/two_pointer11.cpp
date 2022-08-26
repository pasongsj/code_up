#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;

    int ans = 0, R = 0;
    unordered_set<char> checked;

    for(int i=0;i<s.length();i++){
        while(checked.find(s[R]) == checked.end() && R<s.length()){
            checked.insert(s[R]);
            R++;
        }
        ans = max(ans,R-i);
        checked.erase(s[i]);
    }
    cout<<ans;
    return 0;
}
