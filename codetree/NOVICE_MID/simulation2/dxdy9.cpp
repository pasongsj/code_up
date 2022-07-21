#include <iostream>
using namespace std;

bool in_range(int x,int y,int n){
    return(0<=x && x<n && 0<=y && y<n);
}

int main(){
    int n,dir,pos,x,y,cnt = 0;
    cin >> n;
    char arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cin>>arr[i][j];
    }
    cin >> pos;

    int dx[4] = {1,-1,0,0};//남 북 서 동
    int dy[4] = {0,0,-1,1};

    dir = (pos-1)/n;
    if(dir == 0){//남
        x = 0;
        y = pos-1;
    }
    else if(dir == 1){//북
        x = pos-n-1;
        y = n-1;
        dir = 2;
    }
    else if(dir == 2){//서
        x = n-1;
        y = n - (pos - 2*n); // 3n - pos
        dir = 1;
    }
    else{//동
        x = n - (pos - 3*n); // 4n -pos
        y = 0;
    }

    while(true){
        if(arr[x][y]=='/')  dir = (dir+2)%4;
        else    dir = 3-dir;
        x += dx[dir];
        y += dy[dir];
        cnt++;
        if(!in_range(x,y,n))    break;
    }
    cout<<cnt;
    return 0;

}

// '/' dir 남서/ 북동 0 2/ 1 3  
// '\' dir 남동/ 북서 0 3/ 2 1
