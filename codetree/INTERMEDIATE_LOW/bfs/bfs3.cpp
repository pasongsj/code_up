#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_N 100
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n,start_val,max_val;
queue<pair<int,int>> q;

int pointx,pointy;

bool in_range(int x, int y){
    return (0<=x && x<n && 0<=y && y<n);
}

bool can_go(int x,int y){
    return (in_range(x,y) && arr[x][y]<start_val && !visited[x][y]);
}

void bfs(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        int x,y;
        pair<int,int> cur = q.front();
        tie(x,y) = cur;
        q.pop();
        if(arr[x][y]<start_val){
            if(arr[x][y]> max_val || arr[x][y] == max_val && cur<make_pair(pointx,pointy)){
                max_val = arr[x][y];
                pointx = x;
                pointy = y;
              //  cout<<x <<' '<< y<<endl;
            }
        }

        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy)){
                visited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx,tmpy));
            }
        }
    }
}
void init_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
}

int main(){
    int k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    int r,c;
    cin >> r >> c;
    pointx = r-1, pointy = c-1;
    while(k--){
        pair<int,int> cur = make_pair(pointx,pointy);
        visited[pointx][pointy] = true;
        start_val = arr[pointx][pointy];
        q.push(cur);
        max_val = 0;
        bfs();
        init_visited();
        
    }
    cout<<pointx+1<<' '<<pointy+1;
    return 0;


}
