#include <iostream>
using namespace std;

bool in_range(int a,int b,int m){
    if(0<=a && a<m && 0<=b && b<m)    return true;
    return false;
}

int main(){
    int n,cnt,x,y,result = 0;
    cin >> n;
    int arr[n][n];

    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt = 0;
            for(int k=0;k<4;k++){
                x = i+dx[k];
                y = j+dy[k];
                if(in_range(x,y,n)&&arr[x][y]==1) cnt++;
            }
            if(cnt >= 3)    result++;
        }
    }
    cout<< result;

