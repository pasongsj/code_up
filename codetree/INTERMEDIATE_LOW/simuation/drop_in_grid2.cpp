#include <iostream>
using namespace std;
int arr[200][200];
int tmp_arr[200][200];
int n;
bool in_range(int a,int b){
    return (0<=a && a<n && 0<=b && b<n);
}

void bomb(int x, int y){
    int tmpx,tmpy,ran = arr[x][y];
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        for(int j=1;j<ran;j++){
            tmpx = x+dx[i]*j;
            tmpy = y+dy[i]*j;
            if(in_range(tmpx,tmpy)){
                arr[tmpx][tmpy] = 0;
            }
        }
    }
    arr[x][y] = 0;
}
void gravity(int n){
    int row;
    for(int j=0;j<n;j++){
        row = n-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i][j]!=0)    tmp_arr[row--][j] = arr[i][j];
        }
        
    }
    //tmp_arr에서 arr로 옮기기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = tmp_arr[i][j];
            tmp_arr[i][j] = 0;
        }
    }
}

int main(){
    int r,c;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    cin >> r >> c;
    bomb(r-1,c-1);
    gravity(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
