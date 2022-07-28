#include <iostream>
#include <tuple>
//#include <algorithm>
using namespace std;

#define MAX_N 50

int n, m;
int arr[MAX_N][MAX_N];
bool sinked[MAX_N][MAX_N];


bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<m);
}
bool can_go(int x, int y){
    return(in_range(x,y) && arr[x][y] && !sinked[x][y]);
}

int dfs(pair<int,int>cur){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int x,y;
    tie(x,y) = cur;
    for(int i=0;i<4;i++){
        int tmpx = x+dx[i], tmpy = y+dy[i];
        if(can_go(tmpx,tmpy)){
            sinked[tmpx][tmpy] = true;
            dfs(make_pair(tmpx,tmpy));
        }
    }
}
void check_sinked(int k){
    for(int a=0;a<n;a++){// 잠긴마을 체크
        for(int b=0;b<m;b++){
            if(arr[a][b]<=k)    sinked[a][b] = true;
        }
    }
}

void init_sinked(){
    for(int a=0;a<n;a++){// 잠긴마을 초기화
        for(int b=0;b<m;b++){
            sinked[a][b] = false;
        }
    }

}

int main(){
    int cnt,max_k = 1,ans = 0;
    cin >> n >> m;
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            k = (k>arr[i][j]?k:arr[i][j]);
        }
    }

    for(int i=1;i<k;i++){//비 높이
        init_sinked();// 잠긴마을 초기화
        check_sinked(i);// 잠긴마을 체크
        cnt = 0;//인접영역 수
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(!sinked[a][b]){
                    cnt++;
                    sinked[a][b] = true;
                    dfs(make_pair(a,b));

                }
            }
        }
        if(ans<cnt){//최대 영역 갱신
            max_k = i;
            ans = cnt;
        }
    }
    cout<<max_k<<' '<<ans;
    return 0;

}
