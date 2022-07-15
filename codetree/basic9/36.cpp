#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    char t1 = s[1];
    for(int i=1;i<s.length();i++){
        if(s[i] == t1)    s[i] = s[0];
    }
    cout<<s;
    return 0;
}
