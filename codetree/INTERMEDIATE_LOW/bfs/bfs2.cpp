#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_N 100
int n,ans;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<pair<int,int>> q;

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

bool can_go(int a, int b){
    return(in_range(a,b) && arr[a][b]==0 && visited[a][b]==false);
}

void bfs(){
    int x,y;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        pair<int,int> cur_point = q.front();
        tie(x,y) = cur_point;
        q.pop();
        ans ++;
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy)){
                visited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx,tmpy));
            }
        }

    }

    
}

int main(){
    int k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1)    visited[i][j] = true;
        }
    }
    ans = 0;

    for(int i=0;i<k;i++){
        int r,c;
        cin >> r >> c;
        if(visited[--r][--c]==false){
            pair<int,int> cur = make_pair(r,c);
            visited[r][c] = true;
            q.push(cur);
        }
        bfs();
    }
    cout<<ans;
    return 0;

}
