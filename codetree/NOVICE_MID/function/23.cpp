#include <iostream>
#include <string>
using namespace std;

bool same(string &t){
    char a = t[0];
    for(int i=1;i<t.length();i++){
        if(t[i]!= a){
            return true;
        }
    }
    return false;
}
int main(){
    string s;
    cin >> s;
    if(same(s))  cout<<"Yes";
    else    cout<<"No";
    return 0;
}
