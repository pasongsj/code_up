#include <iostream>
using namespace std;

bool in_range(int a,int b,int n){
    return (0<=a && a<n && 0<=b && b<n);
}
int main(){
    int n;
    cin >> n;
    int arr[n][n] = {};
    
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};

    int x = n/2, y = n/2, dir = 3,cnt = 1,ch_dir = 0;
    int tmpx,tmpy;

    while(cnt <= n*n){
        arr[x][y] = cnt;

        dir = (dir+1)%4;
        tmpx = x + dx[dir];
        tmpy = y + dy[dir];

        if(!in_range(tmpx,tmpy,n)||arr[tmpx][tmpy]!= 0)  dir = (dir+3)%4;

        x += dx[dir];
        y += dy[dir];
        cnt ++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
