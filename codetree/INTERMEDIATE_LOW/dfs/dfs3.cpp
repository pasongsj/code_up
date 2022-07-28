#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 25
int n,village;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> person;
int cnt;

pair<int,int> find_point(){
    int x=-1,y=-1;
    bool f_point = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == false){
                x=i,y=j;
                f_point = true;
                break;
            }
        }
        if(f_point) break;
    }
    return make_pair(x,y);
}


bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}
bool can_go(int x, int y){
    return(in_range(x,y) && arr[x][y] && !visited[x][y]);
}

int dfs(pair<int,int>cur){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int x,y;
    tie(x,y) = cur;
    for(int i=0;i<4;i++){
        int tmpx = x+dx[i], tmpy = y+dy[i];
        if(can_go(tmpx,tmpy)){
            cnt++;
            visited[tmpx][tmpy] = true;
            dfs(make_pair(tmpx,tmpy));
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==0)    visited[i][j] = true;
        }
    }

    village = 0;


    while(true){
        pair<int,int> cur = find_point();//새로운 마을 포인트 찾기
        if(cur==make_pair(-1,-1))    break;//더이상의 새로운 마을이 없음
        village++;//새로운 마을이 있음

        cnt = 1;//한 마을의 사람 수
        visited[cur.first][cur.second] = true;//현재 위치 방문체크
        dfs(cur);
        person.push_back(cnt);
    }

    //출력
    cout<<village<<endl;
    sort(person.begin(),person.end());
    for(int i=0;i<person.size();i++){
        cout<<person[i]<<endl;
    }
    return 0;

}
