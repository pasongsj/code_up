#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=2*n-1; i++){
        for(int j=0; j<abs(n-i); j++)   cout<<" ";
        for(int k=1; k<=2*(n-abs(n-i))-1;k++)   cout<<"*";
        cout<<endl;
    }
    return 0;
}
