#include <iostream>
#include <tuple>
using namespace std;

#define MAX_N 100
int n,m,ans;
int arr[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<m);
}
void dfs(pair<int,int> cur){
    if(cur == make_pair(n-1,m-1)){
        ans = 1;
    }
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    int x,y;
    tie(x,y) = cur;
    for(int i=0;i<2;i++){
        int tmpx,tmpy;
        tmpx = x+dx[i], tmpy = y+dy[i];
        if(in_range(tmpx,tmpy)){
            if(arr[tmpx][tmpy]==1 && visited[tmpx][tmpy]==false){
                visited[tmpx][tmpy] = true;
                dfs(make_pair(tmpx,tmpy));
            }
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cin>>arr[i][j];
    }
    pair<int,int>start = make_pair(0,0);//시작점
    visited[0][0] = true;
    ans = 0;
    dfs(start);
    cout<<ans;
    return 0;
}
