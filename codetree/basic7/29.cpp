#include <iostream>
using namespace std;
int main(){
    int n,m,index = 0,result = 0;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int j=0;j<m;j++)    cin>>b[j];

    for(int k=0;k<n-m+1;k++){
        if(a[k]==b[0]){
            result = 1;
            for(int l=1;l<m;l++){
                if(a[k+l]!=b[l]){
                    result = 0;
                    break;
                }
            }
        }
        if(result == 1) break;
    }
    if(result == 0) cout<<"No";
    else    cout<<"Yes";
    return 0;
}
