#include <iostream>
#include <string>
using namespace std;

void to_decimla(int &n){
    string s = to_string(n);
    int sum = 0;
    for(int i=0;i<s.length();i++){
        sum = sum*2+(int)(s[i]-'0');
    }
    n = sum;
}
string to_binary(int &n){
    string s;
    while(n>0){
        s = to_string(n%2) + s;
        n /= 2;
    }
    if(s.length() == 0) s += "0";
    return s;
}

int main(){
    int n;
    string ans;
    cin >> n;

    to_decimla(n);//2진법에서 10진법으로

    n *= 17;
    ans = to_binary(n);//10진법에서 2진법으로
    cout<<ans;
    return 0;
}
