#include <iostream>
#include <tuple>
using namespace std;
int arr[100][100];
int n;

// 1->'/' 남<->서, 북<->동
int dx[4] = {1, -1, 0, 0};//남북동서 
int dy[4] = {0, 0, 1, -1};

// 2->'\' 남<->동, 북<->서
// int dx2[4] = {1, -1, 0, 0};//남북서동
// int dy2[4] = {0, 0, -1, 1};


pair<int,int> start_point(int dir, int pos){
    // 0 -> 0,0~ 0,n-1
    // 1 -> n-1,0~,n-1,n-1
    // 2 -> 0,0~ n-1,0
    // 3 -> 0,n-1,n-1,n-1
    if(dir == 0){
        return make_pair(0,1*pos);//2
    }
    else if(dir == 1){
        return make_pair(n-1,1*pos);//n-1,1*pos
    }
    else if(dir == 2){
        return make_pair(1*pos,0);//1*pos,0
    }
    else{
        return make_pair(1*pos,n-1);//1*pos,n-1
    }
}
bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

int mov(pair<int,int> p,int d){
    int x,y;
    tie(x,y) = p;
    int cnt = 1; //들어옴 생략
    int n_x,n_y;

    if(arr[x][y]==1)    d = 3-d;//시작 위치에 방향 변경이 있는 경우
    else if(arr[x][y]==2)   d = (d+2)%4;

    while(true){
        cnt++;
        n_x = x+dx[d],n_y = y+dy[d]; // 다음 위치
        if(!in_range(n_x,n_y))  return cnt; // 격자 밖으로 나가는 경우
        
        x = n_x;
        y = n_y;

        if(arr[x][y]==1)    d = 3-d; // '/'을 만나 방향 변경
        else if(arr[x][y]==2)   d = (d+2)%4; //'\'을 만나 방향 변경
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    int tmp,ans = 0;
    for(int i=0;i<4;i++){//dir
        for(int j=0;j<n;j++){
            pair<int,int> pos(start_point(i,j)); //시작점 
            tmp = mov(pos,i);
            if(tmp > ans)   ans = tmp;
        }
    }
    cout<<ans;
    return 0;
}
