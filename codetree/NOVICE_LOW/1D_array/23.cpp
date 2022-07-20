#include<iostream>
using namespace std;
int main(){
    int n;
    int m[10]={0,};
    cin >> n;
    while(n!=0){
        if(n/10>0)  m[n/10-1]++;
        cin >> n;
    }
    for(int i=10;i>0;i--){
        cout<<i*10<<" - "<<m[i-1]<<endl;
    }
    return 0;
}

