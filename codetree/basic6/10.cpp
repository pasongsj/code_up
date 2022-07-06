#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)   cout<<"*";
        cout<<"\n\n";
    }
    for(int k=n-1;k>0;k--){
        for(int l=1;l<=k;l++)    cout<<"*";
        cout<<"\n\n";
    }
    return 0;
}
