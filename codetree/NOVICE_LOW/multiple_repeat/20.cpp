#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=2*n;i++){
        if(i%2==0)  for(int j=1;j<i/2+1;j++)   cout<<"* ";
        else    for(int k=1; k<n-i/2+1;k++)    cout<<"* ";
        cout<<endl;
    }
    return 0;
}
