#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n, k,cnt = 0;
    string t;
    cin >> n >> k >> t;
    string s[n],ans[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(t.compare(s[i].substr(0,t.length()))==0) ans[cnt++] = s[i];
    }
    sort(ans,ans+cnt);
    cout<<ans[k-1];
    return 0;
}
