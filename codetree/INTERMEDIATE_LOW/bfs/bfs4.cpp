#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX_N 100


int arr[MAX_N][MAX_N];
int tmparr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool tmpvisited[MAX_N][MAX_N];
int n,k,m,ans,max_rout;

vector<pair<int,int>> s_point;//입력받은 시작지점
vector<pair<int,int>> stone; // 돌 위치
vector<pair<int,int>> choosed; // 선택한 돌
queue<pair<int,int>> q; //bfs queue


bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

bool can_go(int a, int b){
    return(in_range(a,b) && tmparr[a][b]==0 && tmpvisited[a][b]==false);
}
void bfs(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!q.empty()){
        int x,y;
        pair<int,int>cur = q.front();
        tie(x,y) = cur;
        max_rout ++;
        q.pop();
        for(int i=0;i<4;i++){
            int tmpx = x+dx[i],tmpy = y+dy[i];
            if(can_go(tmpx,tmpy)){
                tmpvisited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx,tmpy));
            }
        }
        
    }
}

void cpy_arr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmparr[i][j]=arr[i][j];
            tmpvisited[i][j] = visited[i][j];
        }
    }
    int x, y;
    for(int i=0;i<choosed.size();i++){
        tie(x,y) = choosed[i];
        tmparr[x][y] = 0;
        tmpvisited[x][y] = false;
    }
}

int cal(){
    int result =0;
    for(int i=0;i<s_point.size();i++){
        cpy_arr();//임시 arr, visited생성
        max_rout = 0;
        pair<int,int> cur = s_point[i];
        if(!tmpvisited[cur.first][cur.second]){
            tmpvisited[cur.first][cur.second] = true;
            q.push(cur);
        }
        bfs();//bfs
        result = max(max_rout,result);
    }
    return result;

}


void Choose(int cur_num,int index){//치울 돌 선택 backtracking
    if(cur_num == m+1){
        int tmp = cal();//m개의 돌을 치웠을 때 루트
        ans = max(ans,tmp);
    }
    for(int i=index;i<stone.size();i++){
        choosed.push_back(stone[i]);
        Choose(cur_num+1,i+1);
        choosed.pop_back();
    }
}

int main(){
    cin >> n >> k >> m;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                stone.push_back(make_pair(i,j));
                visited[i][j] = true;
                cnt++;
            }    
        }
    }
    m = (m > cnt ? cnt : m);
    int r,c;
    for(int i=0;i<k;i++){
        cin >> r >> c;
        s_point.push_back(make_pair(--r,--c));
    }
    ans = 0;
    Choose(1,0);// stone_pos.size() 개수 중 k개 선택
    cout<<ans;

    return 0;

}
