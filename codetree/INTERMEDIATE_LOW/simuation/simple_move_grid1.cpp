#include <iostream>
using namespace std;

int arr[100][100];
bool in_range(int x,int y,int n){
    return (0<=x&&x<n &&0<=y&&y<n);
}

int main(){
    int n,r,c;
    cin >> n >> r >> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    //상하좌우 우선순위
    r--;
    c--;
    int cur = arr[r][c];
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool is_change = false;
    while (true){
        is_change = false;
        cout<<cur<<' ';
        for(int i=0;i<4;i++){
            int tmpr = r+dx[i],tmpc = c+dy[i];
            if(in_range(tmpr,tmpc,n) && arr[tmpr][tmpc]>cur){
                r = tmpr;
                c = tmpc;
                cur = arr[tmpr][tmpc];
                is_change = true;
                break;
            }
        }
        if(!is_change)  break;
    }
    return 0;

}
