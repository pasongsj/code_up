#include <iostream>
using namespace std;
int cal_fun(int n){
    if(n == 0)  return 0;
    return cal_fun(n/10)+(n%10)*(n%10);
}

int main(){
    int n;
    cin >> n;
    cout<<cal_fun(n);
    return 0;
}
