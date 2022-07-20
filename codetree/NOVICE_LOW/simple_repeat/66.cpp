#include <iostream>
using namespace std;
int main(){
    int n, attemp= 3;
    while(1){
        cin >> n;
        if(n%2==0)  {
            cout<<n/2<<endl;
            attemp--;
        }
        if(attemp==0)   break;
    }
    return 0;
}
