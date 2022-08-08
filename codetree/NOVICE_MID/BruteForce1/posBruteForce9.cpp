#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+2;j<n;j++){
            if(s[i] == '(' && s[i+1] == '(' && s[j] == ')' && s[j+1] == ')')   ans++;
        }
    }
    cout<<ans;
    return 0;
}
