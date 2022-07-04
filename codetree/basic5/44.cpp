#include<iostream>
using namespace std;
int main(){
    int a, b, sum_val = 0;
    cin >> a >> b;
    for(int i=(a>b?b:a);i<=(a>b?a:b);i++)   if(i%5==0)  sum_val += i;
    cout << sum_val;
    return 0;
}
