#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_N 100
int n,h,m;//h : 사람 수 , m : 비를 피할 공간

int arr[MAX_N][MAX_N];
bool e_visited[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];
int ans[MAX_N][MAX_N];

vector<pair<int,int>>s_pos;// 사람 시작점
vector<pair<int,int>> fin_pos; // 사람 목표점
queue<pair<int,int>> q;

// 0 : 이동 가능공간
// 1 : 벽
// 2 : 사람이 서있음
// 3 : 비를 피할 수 있는 공간
// 1칸이동 당 1초 소요
bool in_range(int x, int y){
    return (0<=x && x<n && 0<=y && y<n);
}

bool can_go(int x,int y){
    return (in_range(x,y)&& arr[x][y]!=1&&!visited[x][y]);
}

void bfs(){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        pair<int,int> cur = q.front();
        int x,y;
        tie(x,y) = cur;
        q.pop();
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy)){
                visited[tmpx][tmpy] = true;
                step[tmpx][tmpy] = step[x][y]+1;
                q.push(make_pair(tmpx,tmpy));
            }
        }

    }
}
void init_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = e_visited[i][j];
            step[i][j] = 0;
        }
    }
}
int find_min(){
    int min_val = 0;
    for(int j=0;j<fin_pos.size();j++){
        pair<int,int> tmp = fin_pos[j];
        int nx,ny;
        tie(nx,ny) = tmp;
        if(step[nx][ny]!=0){
            if(min_val == 0){
                min_val = step[nx][ny];
            }
            else{
                min_val = min(step[nx][ny],min_val);
            }
        }
    }
    if(min_val == 0)    return  -1;
    return min_val;
}

int main(){
    cin >> n >> h >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)    e_visited[i][j] = true;
            else if(arr[i][j] == 2){
                s_pos.push_back(make_pair(i,j));
            }
            else if(arr[i][j] == 3){
                fin_pos.push_back(make_pair(i,j));
            }
        }
    }
    int min_val;
    for(int i=0;i<s_pos.size();i++){
        init_visited();
        pair<int,int>cur = s_pos[i];
        int x,y;
        tie(x,y) = cur;
        if(!visited[x][y]){
            visited[x][y] = true;
            step[x][y] = 0;
            q.push(cur);
        }
        bfs();
        ans[x][y] = find_min();

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;

}
