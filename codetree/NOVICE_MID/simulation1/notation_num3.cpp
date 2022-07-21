#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,b;
    cin >> n >> b;
    string s;
    while(n>0){
        s = to_string(n%b)+s;
        n /= b;
    }
    if(s.length() == 0) s += "0";
    cout<<s;
    return 0;
}
