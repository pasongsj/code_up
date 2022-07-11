#include <iostream>
using namespace std;
int main(){
    int n[10];
    cin>>n[0]>>n[1];
    for(int i=2;i<10;i++){
        n[i]=(n[i-1]+n[i-2])%10;
    }
    for(int j=0;j<10;j++){
        cout<<n[j]<<' ';
    }
    return 0;
}
