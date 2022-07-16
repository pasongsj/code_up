#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string s,t;
    string a,b;
    cin >> s >> t;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]) == 0)  continue;
        a += s[i];
    }
    for(int i=0;i<t.length();i++){
        if(isdigit(t[i]) == 0)  continue;
        b += t[i];
    }
    cout<< stoi(a)+stoi(b);
    return 0;
}
