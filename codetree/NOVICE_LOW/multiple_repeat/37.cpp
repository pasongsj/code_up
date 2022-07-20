#include<iostream>
using namespace std;
int main(){
    int n,cnt = 9;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(i%2==1)  for(int j=1;j<=n;j++)   cout<<n*(i-1)+j<<' ';
        else for(int k=n;k>0;k--)    cout<<n*(i-1)+k<<' ';
        cout<<endl;
    }
    return 0;
}

