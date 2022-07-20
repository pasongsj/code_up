#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, req;
    cin >> s >> req;
    for(int i=0;i<req.length();i++){
        if(req[i] == 'L')   s = s.substr(1,s.length()-1) + s[0];
        else    s = s[s.length()-1] + s.substr(0,s.length()-1);
    }
    cout << s;
    return 0;
}
