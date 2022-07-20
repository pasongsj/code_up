#include <iostream>
using namespace std;
int cal_fun(int n){
    if(n==1)    return 2;
    else if(n==2)   return 4;
    return (cal_fun(n-1)*cal_fun(n-2))%100;
}

int main(){
    int n;
    cin >> n;
    cout<<cal_fun(n);
    return 0;
}
