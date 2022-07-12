#include <iostream>
using namespace std;
int main(){
    int n,q, num,a,b, idx;
    cin >> n >> q;
    int m[n];
    for(int i=0;i<n;i++)    cin >> m[i];
    for(int j=0;j<q;j++){
        idx = 0;
        cin >> num >> a;
        if(num==1){
            cout<<m[a-1]<<endl;
        }
        else if(num==2){
            for(int l=0;l<n;l++){
                if(m[l]==a){
                    idx = l+1;
                    break;
                }
            }
            cout << idx<<endl;
        }
        if(num==3){
            cin>>b;
            for(int x=a;x<=b;x++)   cout<<m[x-1]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
