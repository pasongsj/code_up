#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define MAX_N 100

int n,m;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

queue<pair<int,int>> q;


bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<m);
}

void bfs(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    while(!q.empty()){
        int x,y;
        pair<int,int> cur = q.front();
        q.pop();
        tie(x,y) = cur;
        for(int i=0;i<4;i++){
            int tmpx,tmpy;
            tmpx = x+dx[i], tmpy = y+dy[i];
            if(in_range(tmpx,tmpy)&& arr[tmpx][tmpy]==1 && visited[tmpx][tmpy]==false){
                visited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx,tmpy));
                
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cin >> arr[i][j];
    }

    q.push(make_pair(0,0));
    visited[0][0] = true;
    bfs();
    cout << visited[n - 1][m - 1];
    return 0;
}

