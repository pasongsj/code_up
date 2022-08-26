#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map <char,int> dup;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int k;
    cin >> k;

    int ans = 0,R = 0;
    for(int i=0;i<s.length();i++){
        while(dup.size()<=k && R<s.length()){
            dup[s[R++]] += 1;
        }

        if(dup.size()>k) ans = max(ans,R-i-1);
        else    ans = max(ans,R-i);

        dup[s[i]]--;
        if(dup[s[i]]==0)    dup.erase(s[i]);
    }
    cout<<ans;
    return 0;

}
