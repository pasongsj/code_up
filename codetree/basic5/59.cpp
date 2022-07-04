#include <iostream>
using namespace std;
int main(){
    int n,i,mul_val = 1;
    cin >> n;
    for(i=1;i<=10;i++){
        mul_val *= i;
        if(mul_val>=n)   break;
    }
    cout<<i;
    return 0;
}
