#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            s[i] = '1';
            break;
        }
        if(i == n-1 && s[n-1] == '1') s[n-1]='0';
        else if(i == n-1 && s[n-1] == '0')  s[n-1]='1';
    }
    
    int ans = 0, bin = 1;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == '1'){
            ans += bin;
        }
        bin *= 2;
    }
    cout<<ans;
    return 0;
}
