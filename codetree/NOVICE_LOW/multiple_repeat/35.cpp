#include<iostream>
using namespace std;
int main(){
    int n,cnt = 9;
    cin >> n;
    for(int i=0;i<n;i++){
        if(i%2==0)  for(int j=1;j<=n;j++)   cout<<j;
        else    for(int k=n;k>0;k--)    cout<<k;
        cout<<endl;
    }
    return 0;
}

