#include <iostream>
#include <utility>
using namespace std;
#define N 19
int arr[N][N];

bool in_range(int x,int y){
    return (0<=x && x<N && 0<=y && y<N);
}

pair<int,int> is_omok(int x ,int y){
    int dx[4] = {1,1,1,0};
    int dy[4] = {-1,0,1,1};
    bool is_col;
    int tmpx = x, tmpy = y;
    for(int i=0;i<4;i++){
        is_col = true;
        for(int j=1;j<5;j++){
            if(in_range(x+dx[i]*j, y+dy[i]*j) && arr[tmpx][tmpy] != arr[x+dx[i]*j][y+dy[i]*j]){
                is_col = false;
                break;
            }
            else if(!in_range(x+dx[i]*j, y+dy[i]*j)){
                is_col = false;
                break;
            }
            tmpx = x+dx[i]*j, tmpy = y+dy[i]*j;
        }
        if(is_col){
            return make_pair(x+dx[i]*2,y+dy[i]*2);
        }
    }
    return make_pair(-1,-1);
}




int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == 1 || arr[i][j] == 2){
                pair<int,int> tmp = is_omok(i,j);
                if(tmp != make_pair(-1,-1)){
                    cout<<arr[i][j]<<endl;
                    cout<<tmp.first+1<<' '<<tmp.second+1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
    
}
