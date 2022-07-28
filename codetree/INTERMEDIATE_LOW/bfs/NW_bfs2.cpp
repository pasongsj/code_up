#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_N 100

int n,ans;
bool visited[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

queue<pair<int,int>> q;

bool in_range(int x,int y){
    return (0<=x && x<n && 0<=y && y<n);
}

bool can_go(int x, int y){
    return (in_range(x,y)&&!visited[x][y]);
}

void bfs(){
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {-1,-2,-2,-1,1,2,2,1};
    while(!q.empty()){
    //    pair<int,int> cur = q.front();
        int x, y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy)){
                visited[tmpx][tmpy] = true;
                step[tmpx][tmpy] = step[x][y]+1;
                q.push(make_pair(tmpx,tmpy));
            }
        }
    }
}


int main(){
    int r1,c1,r2,c2;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    r2--;
    c1--;
    c2--;

    ans = 0;
    pair<int,int> cur = make_pair(r1,c1);
    visited[r1][c1] = true;
    q.push(cur);
    step[r1][c1] = 0;
    bfs();
    if(r1 == r2 && c1 == c2)    cout<<0;
    else if(step[r2][c2]== 0)    cout<<-1;
    else    cout<<step[r2][c2];
    return 0;
}
