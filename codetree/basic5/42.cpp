#include<iostream>
using namespace std;
int main(){
    int n,sum_val = 0;
    cin >> n;
    for(int i=n;i<=100;i++) sum_val += i;
    cout << sum_val;
    return 0;
}
