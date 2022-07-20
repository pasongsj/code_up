#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=2*n-1;i++){
        for(int j=abs(n-i);j>0;j--) cout<<" ";
        for(int k=1;k<=n-abs(n-i);k++)  cout<<"* ";
        cout<<endl;
    }
    return 0;
}
