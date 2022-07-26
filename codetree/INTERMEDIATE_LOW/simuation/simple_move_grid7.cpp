#include <iostream>
using namespace std;
int arr[100][100];
int n;

// 1->'/' 남<->서, 북<->동
int dx1[4] = {1, -1, 0, 0};//남북동서 
int dy1[4] = {0, 0, 1, -1};
// 2->'\' 남<->동, 북<->서
int dx2[4] = {1, -1, 0, 0};//남북서동
int dy2[4] = {0, 0, -1, 1};


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
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;<n;j++) cin>>arr[i][j];
    }
    int ans = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            tmp = mov(i,j);
            if(tmp > ans)   ans = tmp;
        }
    }
}
