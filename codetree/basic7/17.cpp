#include <iostream>
using namespace std;
int main(){
    int n[100];
    int i;
    for(i=0;i<100;i++){
        cin>>n[i];
        if(n[i]==0) break;
        if(n[i]%2==1){
            n[i]+= 3;
        }
        else{
            n[i] /= 2;
        }
    }
    for(int j=0;j<i;j++){
        cout<<n[j]<<' ';
    }
    return 0;
}
