#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m[n];
    for(int i=0;i<n;i++)    cin >> m[i];
    for(int j=n-1;j>=0;j--){
        if(m[j] % 2 ==0)   cout<<m[j]<<' ';
    }
    return 0;
}
