#include <iostream>
using namespace std;
char arr[100][100];
int n,x,y;
int dx[4] = {1,0,-1,0};//남 동 북 서
int dy[4] = {0,1,0,-1};//

bool in_range(int a,int b){
    return (0<=a && a<n && 0<=b && b<n);
}
//cout<<x<<':'<<y<<"dir :"<<d<<endl;
int mov(int d){
    int tmp_d;
    int cnt = 0;
    while(true){
        if(!in_range(x+dx[d],y+dy[d])){
            x += dx[d];
            y += dy[d];
            return d;
        }
        if(arr[x+dx[d]][y+dy[d]]=='.'){
            x += dx[d];
            y += dy[d];
            tmp_d = (d+3)%4;
            if(arr[x+dx[tmp_d]][y+dy[tmp_d]]=='.'){
                return tmp_d;
            }
            else{
                return d;
            }
        }
        else{ //if(arr[x+dx[d]][arr[y+dy[d]]]=='#'){
            d = (d+1)%4;
            cnt++;
        }
        if(cnt==4)  return -1;
    }
    return d;
    
}

int main(){
    int time = 0;
    int start_x,start_y;
    //입력
    cin >> n >> x >>y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    x--;
    y--;
    start_x = x;
    start_y = y;
    int dir = 0,cnt = 0;
    while(true){
        dir = mov(dir);
        time ++;
        if(start_x == x && start_y ==y)   cnt++;
        if(!in_range(x,y)){
            break;
        }
        if(cnt>1&&in_range(x,y)||dir == -1){
            time = -1;
            break;
        }
    }
    cout<<time;
    return 0;

}
