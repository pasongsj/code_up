#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i]) == 0){
            s = s.substr(0,i);
            break;
        }
    }
    for(int i=0;i<t.length();i++){
        if(isdigit(t[i]) == 0){
            t = t.substr(0,i);
            break;
        }
    }
    cout<< stoi(s)+ stoi(t);
    return 0;
}
