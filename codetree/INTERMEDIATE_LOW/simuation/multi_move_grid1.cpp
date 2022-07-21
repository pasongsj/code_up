#include <iostream>
#include <tuple>
using namespace std;

int arr[20][20];
int count[20][20];
int next_count[20][20];
int t, n, m;

bool in_range(int x,int y){
    return (0<=x&&x<n &&0<=y&&y<n);
}

tuple<int,int> mov_func(int r, int c){
    int x=r,y=c;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int cur = 0;
    for(int i=0;i<4;i++){
        int tmpr = r+dx[i];
        int tmpc = c+dy[i];
        if(in_range(tmpr,tmpc) && arr[tmpr][tmpc]>cur){
            x = tmpr;
            y = tmpc;
            cur = arr[x][y];
        }
    }
    return tuple<int,int>(x,y);

}


int main(){
    cin >> n >> m >> t;
    int tmp = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin >> arr[i][j];
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        x--;
        y--;
        count[x][y] ++;
    }
    for(int i=0;i<t;i++){//t번 반복

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(count[i][j]==1){
                    auto [a, b]  = mov_func(i,j);
                    next_count[a][b]++;
                }
            }
        }

        //
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(next_count[i][j] >1) next_count[i][j] = 0;
                count[i][j] = next_count[i][j];
                next_count[i][j] = 0;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt+=count[i][j];
        }
    }
    cout<<cnt;
    return 0;

}
