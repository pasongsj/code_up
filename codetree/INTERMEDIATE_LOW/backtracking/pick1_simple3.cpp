#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 20
vector<int>com;

int arr[MAX_N][MAX_N];
int b_arr[MAX_N][MAX_N];
int n,k,ans;

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

void cal(int x,int y,int bom){
    int dx1[5]={2,1,0,-1,-2};
    int dx2[5]={0,-1,1,0,0};
    int dy2[5]={0,0,0,1,-1};
    int dx3[5]={0,-1,-1,1,1};
    int dy3[5]={0,-1,1,-1,1};
    if(bom == 1){
        for(int i=0;i<5;i++){
            if(in_range(x+dx1[i],y)){
                b_arr[x+dx1[i]][y] = 1;
            }
        }
    }
    else if(bom == 2){
        for(int i=0;i<5;i++){
            if(in_range(x+dx2[i],y+dy2[i])){
                b_arr[x+dx2[i]][y+dy2[i]] = 1;
            }
        }
    }
    else{
        for(int i=0;i<5;i++){
            if(in_range(x+dx3[i],y+dy3[i])){
                b_arr[x+dx3[i]][y+dy3[i]] = 1;
            }
        }
    }

}

int bomb(){
    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                cal(i,j,com[index++]);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b_arr[i][j]){
                cnt++;
                b_arr[i][j] = 0;
            }
        }
    }
    return cnt;
}

void Choose(int cur_num){
    if(cur_num == k+1){
        ans = max(bomb(),ans);
        return;
    }
    for(int i=1;i<=3;i++){
        com.push_back(i);
        Choose(cur_num+1);
        com.pop_back();
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]>0) k++;
        }
    }
    ans = 0;
    Choose(1);
    cout<<ans;
    return 0;
}
