#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m[n];
    for(int i=0;i<n;i++){
        cin >> m[i];
        m[i] *= m[i];
    }
    for(int j=0;j<n;j++){
        cout<< m[j]<<' ';
    }
    return 0;
}

