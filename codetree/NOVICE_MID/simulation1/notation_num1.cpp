#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    while(n>0){
        s = to_string(n%2)+s;
        n /= 2;
    }
    if(s.length()==0)   s += "0";
    cout<<s;
    return 0;
}
