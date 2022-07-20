#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=2*n-1; i++){
        if(i<=n)    for(int j=1; j<=n-i+1;j++) cout<<"* ";
        else    for(int k=0; k<=i-n; k++)    cout<<"* ";
        cout<<endl;
    }
    return 0;
}
