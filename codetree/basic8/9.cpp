#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j%2==0)  cout<<n*j+i<<' ';
            else    cout<<n*(j+1)-1-i<<' ';
        }
        cout<<endl;
    }
    return 0;
}
