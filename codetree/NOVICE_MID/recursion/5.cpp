#include <iostream>
using namespace std;
int cal_fun(int n){
    if(n==1)return 1;
    return (n + cal_fun(n-1));
}
int main(){
    int n,result;
    cin >> n;
    result = cal_fun(n);
    cout<<result;
    return 0;
}
