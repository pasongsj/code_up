#include <iostream>
using namespace std;

#define MAX_N 100001
int arr[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>> a >> b;
        int r1 = 0,r2 = 0,r3 = 0;
        for(int j=a;j<=b;j++){
            if(arr[j]==1)   r1++;
            else if(arr[j]==2)  r2++;
            else if(arr[j]==3)  r3++;
        }
        cout<<r1<<' '<<r2<<' '<<r3<<'\n';
    }

    return 0;
}
