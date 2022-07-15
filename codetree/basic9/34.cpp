#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    char t1 = s[0], t2 = s[1];
    for(int i=0;i<s.length();i++){
        if(s[i] == t1)    s[i] = t2;
        else    if(s[i] == t2)    s[i] = t1;
     }
    cout<< s;
    return 0;
}
