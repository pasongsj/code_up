#include <iostream>
#include <string>
using namespace std;

string to_deci(string n, int c){
    int ans = 0,num = 1;
    for(int i=n.length()-1;i>=0;i--){
        ans += (n[i]-'0')*num;
        num*=c;
    }
    return to_string(ans);
}

string to_bnum(string n, int c){
    string ans = "";
    int num = stoi(n);
    while(num>0){
        ans = to_string(num%c) + ans;
        num /= c;
    }
    return ans;
}
int main(){
    int a, b;
    string n, deci, ans;
    cin >> a >> b >> n;
    deci = to_deci(n,a);
    ans = to_bnum(deci,b);
    cout<<ans;
    return 0;
}
