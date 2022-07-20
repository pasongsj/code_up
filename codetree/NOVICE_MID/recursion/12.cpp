#include <iostream>
using namespace std;

int func(int n){
    if(n==0) return 0;
    return n%10 + func(n/10);
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << func(a*b*c);
    return 0;
}
