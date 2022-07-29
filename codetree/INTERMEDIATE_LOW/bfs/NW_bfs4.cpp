#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 100

int n,k,ans;
int r1,c1, r2,c2;

int arr[MAX_N][MAX_N];
int tmp_arr[MAX_N][MAX_N];

bool visited[MAX_N][MAX_N];
bool tmp_visited[MAX_N][MAX_N];

int step[MAX_N][MAX_N];

vector<pair<int,int>> walls;
vector<pair<int,int>> del_wall;
queue<pair<int,int>> q;

void cpy_tmp(){ // arr, visited, step 초기화
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp_arr[i][j] = arr[i][j];
            tmp_visited[i][j] = visited[i][j];
            step[i][j] = 0;
        }
    }
}

bool in_range(int x, int y){ // x,y가 범위 안에 있는지
    return (0<=x && x<n && 0<=y && y<n);
}
bool can_go(int x,int y){ // 범위, 갈수 있는 곳, 한번도 방문하지 않는 곳을 만족하는지
    return(in_range(x,y)&&tmp_arr[x][y]==0&&tmp_visited[x][y]==false);
}

void bfs(){//bfs
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy =y+dy[i];
            if(can_go(tmpx,tmpy)){
                tmp_visited[tmpx][tmpy] = true;
                step[tmpx][tmpy] = step[x][y]+1;
                q.push(make_pair(tmpx,tmpy));
            }
        }

    }
}


int cal(){
    cpy_tmp();//arr, visited 복사
    int tmpx,tmpy;
    for(int i=0;i<del_wall.size();i++){//허문 벽 : del_wall 을 이동할 수 있게 변경
        tie(tmpx,tmpy) = del_wall[i];
        tmp_arr[tmpx][tmpy] = 0;
        tmp_visited[tmpx][tmpy] = false;
    }
    pair<int,int> cur = make_pair(r1,c1);
    tmp_visited[r1][c1] = true;
    step[r1][c1] = 0;
    q.push(cur);
    bfs();
    return step[r2][c2];//r2,c2까지 이동한 거리
}

void Choose(int cur_num,int index){// k개의 벽 선택
    if(cur_num == k+1){// k개의 벽을 허물 때
        int tmp = cal();
        if(tmp>0){
            if(ans == 0)    ans = tmp;//이동한 거리를 한번도 초기화 하지 않는 경우
            else    ans = min(tmp,ans); // 이동거리 중 최소
        }
        return;
    }

    for(int i=index;i<walls.size();i++){
        del_wall.push_back(walls[i]);
        Choose(cur_num+1,i+1);
        del_wall.pop_back();
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                visited[i][j] = true;
                walls.push_back(make_pair(i,j)); // 벽 저장
            }
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    Choose(1,0);// 없앨 벽 선택
    if(r1==r2&&c1==c2)  ans = 0; // 시작점과 도착점이 같은 경우
    else if(ans == 0)   ans = -1; // 도착점까지 이동할 수 없는경우
    cout<<ans;
    return 0;
}
