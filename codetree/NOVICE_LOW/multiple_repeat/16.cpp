#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=2*n-1;i++){
        if(i<n) for(int j=1;j<=(n-i);j++)    cout<<"  ";
        for(int k=1;k<=n-abs(n-i);k++)  cout<<"@ ";
        cout<<endl;
    }
    return 0;
}

