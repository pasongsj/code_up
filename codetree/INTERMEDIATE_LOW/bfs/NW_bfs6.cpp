#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_N 100
int n,k;

int arr[MAX_N][MAX_N];
bool tmp_visited[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

vector<pair<int,int>> s_point;// 썩은 귤 시작지점
vector<pair<int,int>> mandarin;
queue<pair<int,int>> q;


void init_visited(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = tmp_visited[i][j];
        }
    }
}
bool in_range(int x,int y){
    return (0<=x && x<n && 0<=y && y<n);
}
bool Can_go(int x, int y){
    return (in_range(x,y) &&arr[x][y]==1 &&!visited[x][y]);
}
void Push(int x, int y,int bx, int by){
    visited[x][y] = true;
    if(step[x][y]==0)   step[x][y] = step[bx][by]+1;
    else    step[x][y] = min(step[x][y],step[bx][by]+1);
    q.push(make_pair(x,y));
}
void bfs(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(Can_go(tmpx,tmpy)){
                Push(tmpx,tmpy,x,y);
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){//빈칸
                tmp_visited[i][j] = true;
                step[i][j] = -1;
            }
            else if(arr[i][j] == 2){//썩은 귤 시작지점
                s_point.push_back(make_pair(i,j));
            }
            else{
                mandarin.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0;i<k;i++){
        init_visited();
        int x,y;
        tie(x,y) = s_point[i];
        visited[x][y] = true;
        step[x][y] = 0;
        q.push(s_point[i]);
        bfs();
    }
    for(int i=0;i<mandarin.size();i++){
        int x,y;
        tie(x,y) = mandarin[i];
        if(step[x][y] == 0) step[x][y] = -2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<step[i][j]<<' ';
        cout<<endl;   
    }
    return 0;

}
