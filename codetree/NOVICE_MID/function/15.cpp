#include <iostream>
using namespace std;
bool is_prime(int k){
    if(k<2) return false;
    else if (k == 2)    return true;
    else{
        for(int i=2;i<=k/2;i++){
            if(k%i==0)  return false;
        }
        return true;
    }
}
bool is_sat(int n){
    int tmp = 0;
    if(is_prime(n)){
        while(n>0){
            tmp += n%10;
            n /= 10;
        }
        if(tmp % 2 == 0)    return true;
    }
    return false;
}
int main(){
    int a,b,cnt = 0;

