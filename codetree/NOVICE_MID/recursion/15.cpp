#include <iostream>
using namespace std;
int cal_fun(int n){
    if(n == 1)  return 1;
    if(n == 2)  return 2;
    return cal_fun(n/3)+cal_fun(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << cal_fun(n);
    return 0;
}
