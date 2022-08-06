#include <iostream>
using namespace std;
#define MAX_NUM 100

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            for(int j=i+1;j<s.length();j++){
                if(s[j] == ')') ans++;
            }
        }
    }
    cout<<ans;
    return 0;

}
