#include <iostream>
using namespace std;
int main(){
    int n[10];
    cin>>n[0]>>n[1];
    for(int i=2;i<10;i++){
        n[i]=n[i-1]+2*n[i-2];
    }
    for(int i=0;i<10;i++){
        cout<<n[i]<<' ';
    }
    return 0;
}
