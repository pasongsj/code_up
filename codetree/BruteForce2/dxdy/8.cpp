#include <iostream>
#include <string>
using namespace std;
bool in_range(int x, int y, int n){
    return (0<=x && x<n && 0<=y && y<n);
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n][n] = {};

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int r,c,tmpx,tmpy,cnt;
    for(int i=0;i<m;i++){
        cin >> r >> c;
        arr[r-1][c-1] = 1;
        cnt = 0;
        for(int j=0;j<4;j++){
            tmpx = r-1+dx[j];
            tmpy = c-1+dy[j];
            if(in_range(tmpx,tmpy,n) && arr[tmpx][tmpy] == 1){
                cnt++;
            }
        }
        if(cnt==3)  cout<<1<<endl;
        else    cout<<0<<endl;    
    }
    return 0;
}

