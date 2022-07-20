#include <iostream>
using namespace std;
int main(){
    int n, m, lim,cnt = 1;
    cin >> n >> m;
    int arr[n][m]={};    //0으로 초기화

    lim = n<m?n:m;
    for(int i=0;i<m;i++){
        for (int j=0;j<=(i>(n-1)?(n-1):i);j++){ //(0,0), (0,1), (0,2), (0,3),...,(0,m) 채우기
            arr[j][i-j] = cnt;
            cnt ++;
        }
    }

    for (int i=1;i<n;i++){
        for(int j=0;j<(n-i>m?m:n-i);j++){ //(1,m), (2,m), (3,m), (4,m),...,(n,m) 채우기  
            arr[i+j][m-j-1]= cnt;
            cnt ++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
