#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    cout << s << endl;
    for(int i=0;i<s.length();i++){
        s = s[s.length()-1] + s.substr(0,s.length()-1);
        cout<< s << endl;
    }
    return 0;
}
