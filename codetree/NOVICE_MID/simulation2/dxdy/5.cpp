#include <iostream>
using namespace std;

bool in_range(int x,int y, int n, int m){
    return (0<=x && x<n && 0<=y && y<m);
}

int main(){
    int n,m,dir = 0;
    cin >> n >> m;
    int arr[n][m] = {};
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    int tmpx,tmpy,x=0,y=0;
    arr[x][y] = 1;
    for(int i=2;i<=n*m;i++){
        tmpx = x+dx[dir];
        tmpy = y+dy[dir];
        if(!in_range(tmpx,tmpy,n,m) || arr[tmpx][tmpy] !=0) dir = (dir+1)%4;
        x += dx[dir];
        y += dy[dir];
        arr[x][y] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;

}
