#include <iostream>
using namespace std;
bool is_prime(int n){
    if(n == 1)  return false;
    for(int i=2;i<n/2;i++){
        if(n%i==0)  return false;
    }
    return true;
}
int main(){
    int a,b,cnt = 0;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        if(is_prime(i)==true)   cnt += i;
    }
    cout<< cnt;
    return 0;
}
