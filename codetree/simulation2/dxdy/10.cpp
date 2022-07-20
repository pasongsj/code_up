#include <iostream>
using namespace std;
bool in_range(int a,int b,int n,int m){
    return (0<=a && a<n && 0<=b && b<m);
}
int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][m] = {};
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    int tmpx, tmpy, dir, x = 0, y = 0;
    dir = 0;
    for(int i=0;i<m*n;i++){
        arr[x][y] = i+1;
        tmpx = x + dx[dir];
        tmpy = y + dy[dir];

        if(!in_range(tmpx,tmpy,n,m) || arr[tmpx][tmpy] != 0)    dir = (dir + 1)%4;
        x += dx[dir];
        y += dy[dir]; 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
