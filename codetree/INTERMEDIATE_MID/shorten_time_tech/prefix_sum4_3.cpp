#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX_N 100001
int arr[MAX_N][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;

    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        for(int j=1;j<=3;j++){
            arr[i][j] = arr[i-1][j];
        }
        arr[i][tmp]++;
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>> a >> b;

        cout<<arr[b][1]-arr[a-1][1]<<' '<<arr[b][2]-arr[a-1][2]<<' '<<arr[b][3]-arr[a-1][3]<<'\n';

    }

    return 0;
}
