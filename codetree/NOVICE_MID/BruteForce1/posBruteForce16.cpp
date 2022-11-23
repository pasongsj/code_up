#include<iostream>
#include<string>
using namespace std;
#define MAX_N 100

int arr[MAX_N][MAX_N];

bool in_range(int x,int y,int n){
    return (0<=x && x<n && 0<=y && y<n);
}
int  main(){
    int n, t;
    cin >> n >> t;
    int dx[4] = {-1,0,1,0}; //북 동 남 서
    int dy[4] = {0,1,0,-1}; 
//R 북 동 남 서 
//L 북 서 남 동 
    string direct;
    for(int i=0;i<t;i++){
        char tmp;
        cin >>tmp;
        direct+=tmp;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int nx = 0, ny = 0;
    nx = ny = (n-1)/2;

    int ans = arr[nx][ny];
    int dir = 0;
    for(int i=0;i<t;i++){
        if(direct[i] == 'R'){
            dir = (dir+1)%4;
        }
        else if(direct[i] == 'L'){
            if(dir == 0)    dir = 3;
            else dir--;
        }
        else{
            if(in_range(nx+dx[dir],ny+dy[dir],n)){
                nx += dx[dir];
                ny += dy[dir];
                ans +=arr[nx][ny];
            }
        }
    }
    cout<<ans;
    return 0;

}
