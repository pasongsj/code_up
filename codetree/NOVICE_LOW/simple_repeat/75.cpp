#include <iostream>
using namespace std;
int main(){
    int a, n=0;
    cin >> a;
    while(a<1000){
        if(a%2==0)  a=a*3+1;
        else    a=a*2+2;
        n++;
    }
    cout<<n;
    return 0;
}
