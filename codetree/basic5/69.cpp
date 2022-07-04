#include <iostream>
using namespace std;
int main(){
    int n, mul_count = 0;
    cin >> n;
    while(1){
        if(n==1)    break;
        if(n%2==0)  n /= 2;
        else    n = 3*n+1;
        mul_count++;
    }
    cout<<mul_count;
    return 0;
}

