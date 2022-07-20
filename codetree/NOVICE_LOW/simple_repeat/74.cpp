#include <iostream>
using namespace std;
int main(){
    int n,val = 0;
    cin >> n;
    while(1){
        if(n==1)    break;
        n/=2;
        val++;
    }
    cout<<val;
    return 0;
}
