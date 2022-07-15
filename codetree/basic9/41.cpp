#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t;
    cin >> s;
    t = s.substr(1,s.length()-1)+ s[0];
    cout<<t;
    return 0;
}
