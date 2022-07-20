#include <iostream>
using namespace std;
int cal_fun(int n){
    if(n==1)    return 0;
    if(n%2==0)  return 1 + cal_fun(n/2);
    return 1+cal_fun(n/3);
    
}

int main(){
    int n;
    cin >> n;
    cout<<cal_fun(n);
    return 0;
}
