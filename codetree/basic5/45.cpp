#include<iostream>
using namespace std;
int main(){
    int a, b, sum_val = 0;
    cin >> a >> b;
    for(int i=(a+1)/2*2;i<=b;i+=2)  sum_val+=i;
    cout << sum_val;
    return 0;
}
