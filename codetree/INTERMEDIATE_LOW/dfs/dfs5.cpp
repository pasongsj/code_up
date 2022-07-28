#include <iostream>
#include <tuple>
using namespace std;

#define MAX_N 100
int n,cnt;
int arr[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];


bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}
bool can_go(int x, int y, int bx, int by){
    return(in_range(x,y) && arr[x][y]==arr[bx][by] && !visited[x][y]);
}

int dfs(pair<int,int>cur){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int x,y;
    tie(x,y) = cur;
    for(int i=0;i<4;i++){
        int tmpx = x+dx[i], tmpy = y+dy[i];
        if(can_go(tmpx,tmpy,x,y)){
            visited[tmpx][tmpy] = true;
            cnt++;
            dfs(make_pair(tmpx,tmpy));
        }
    }
}




int main(){
    int num = 0,bomb = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                cnt = 1;
                dfs(make_pair(i,j));
                bomb = cnt>bomb?cnt:bomb;
                if(cnt>=4){
                    num++;
                }
            }
        }
    }
    cout<<num<<' '<<bomb;
    return 0;
}
