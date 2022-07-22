#include <iostream>
#include <algorithm>
using namespace std;

int arr[200][200];
int n,m;

bool in_range(int x, int y){
    return (0<=x && x<n && 0<=y && y<m);
}

//i j 
int max(){
    int tmp, tmpx, tmpy, ans = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int index[4] = {};
            for(int k=0;k<4;k++){
                tmpx = i+dx[k];
                tmpy = j+dy[k];
                if(in_range(tmpx,tmpy)){
                    index[k] = arr[tmpx][tmpy];
                }
            }
            sort(index,index+4,greater<int>());
            tmp = arr[i][j] + index[0]+index[1];
            if(tmp > ans)   ans = tmp;
        }
    }
    return ans;

}



int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    cout<<max();
    return 0;
}
