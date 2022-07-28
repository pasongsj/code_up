#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 8
int n,k,u,d,ans;
int arr[MAX_N][MAX_N];
int tmp;

bool visited[MAX_N][MAX_N];
queue<pair<int,int>> q;
vector<pair<int,int>> s_point;

void init_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    visited[i][j] = false;
    }
}

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

bool can_go(int nx, int ny, int x, int y){
    return (in_range(nx,ny)&& u<=abs(arr[nx][ny]-arr[x][y]) && abs(arr[nx][ny]-arr[x][y])<=d && !visited[nx][ny]);
}

void bfs(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        pair<int,int> cur = q.front();
        int x,y;
        tie(x,y) = cur;
        tmp++;
        q.pop();
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy,x,y)){
                visited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx,tmpy));
            }
        }
    }
}


int cal(){
    init_visited();
    tmp = 0;
    for(int i=0;i<s_point.size();i++){
        int x,y;
        tie(x,y) = s_point[i];
        visited[x][y] = true;
        q.push(s_point[i]);
        bfs();
    }
    return tmp;
}

void Choose(int cur_num){
    if(cur_num == k+1){
        ans = max(ans ,cal());
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s_point.push_back(make_pair(i,j));
            Choose(cur_num+1);
            s_point.pop_back();
        }
    }

}

int main(){
    // k개의 도시 pick 높이 차이가 u이상 d이하인 경우 이동가능
    //이동 가능한 도시 최대로
  //  int result = 0;
    cin >> n >> k >> u >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    ans = 0;
    Choose(1);
    cout<<ans;
    return 0;
    
}
