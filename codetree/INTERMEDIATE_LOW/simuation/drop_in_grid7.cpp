#include <iostream>
using namespace std;
int arr[50][50];
int ch_arr[50][50];
int n;
void ch_arr_init(){ // ch_arr에 arr복사
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ch_arr[i][j] = arr[i][j];
        }
    }
}
bool in_range(int a,int b){
    return (0<=a && a<n && 0<=b && b<n);
}
void bomb(int x, int y){//x,y로 터진부분 0
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int ran = ch_arr[x][y];
    for(int i=0;i<4;i++){
        for(int j=0;j<ran;j++){
            if(in_range(x+dx[i]*j,y+dy[i]*j))   ch_arr[x+dx[i]*j][y+dy[i]*j] = 0;
        }
    }
}
void gravity(){//아래로 sort
    int g_arr[50][50] = {};
    for(int j=0;j<n;j++){
        int index = n-1;
        for(int i=n-1;i>=0;i--){
            if(ch_arr[i][j]>0){
                g_arr[index--][j] = ch_arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ch_arr[i][j] = g_arr[i][j];
        }
    }
}

int find_couple(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<n-1 && ch_arr[i][j]!=0 && ch_arr[i][j] == ch_arr[i][j+1])   ans++;//가로로 쌍
            if(i<n-1 && ch_arr[i][j]!=0 && ch_arr[i][j] == ch_arr[i+1][j])   ans++;//세로로 쌍
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    int tmp,ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //ch_arr초기화
            ch_arr_init();
            //i,j가 터졌을 때
            bomb(i,j);
            //중력작용
            gravity();
            // 쌍 개수 찾기
            tmp = find_couple();
            if(tmp > ans)    ans = tmp;
        }
    }
    cout<<ans;
    return 0;
}
