#include <iostream>
using namespace std;
int arr[100][100];
int ch_arr[100][100];
int n, m, q;

bool in_range(int x,int y,int x1,int y1,int x2,int y2){
    return(x1<=x && x<=x2 && y1<=y && y<=y2);
}
void mov_fun(int x1, int y1, int x2,int y2){
    int dx[4] = {1,0,-1,0};//시계방향 동 남 서 북//반시계방향 남 동 북 서 
    int dy[4] = {0,1,0,-1};
    int tmp = arr[x1][y1];
    int tmpx, tmpy, dir = 0, curx = x1, cury = y1;
    for(int i=0;i<(x2-x1+y2-y1)*2-1;i++){
        tmpx = curx + dx[dir];
        tmpy = cury + dy[dir];
        if(!in_range(tmpx,tmpy,x1,y1,x2,y2)){
            dir = (dir+1)%4;
            tmpx = curx + dx[dir];
            tmpy = cury + dy[dir];
        }
        arr[curx][cury] = arr[tmpx][tmpy];

        curx = tmpx;
        cury = tmpy;
    }
    arr[curx][cury] = tmp;
}

void ch_fun(int x1, int y1, int x2,int y2){
    int dx[4] = {1,0,-1,0}; 
    int dy[4] = {0,1,0,-1};
    int tmp,cnt;

    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){            
            tmp = arr[i][j];
            cnt = 1;
            for(int k=0;k<4;k++){
                if(in_range(i+dx[k],j+dy[k],0,0,n-1,m-1)){
                    tmp += arr[i+dx[k]][j+dy[k]];
                    cnt++;
                }
            }
            ch_arr[i][j] = tmp/cnt;
            
        }
    }
    //복사하기
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            arr[i][j] = ch_arr[i][j];
            ch_arr[i][j] = 0;
        }
    }
}

int main(){
    //입력
    cin >>n >> m >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cin>>arr[i][j];
    }
    int r1[100],c1[100],r2[100],c2[100];
    for(int i=0;i<q;i++){
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
    }

    //이동, 변환
    for(int i=0;i<q;i++){
        mov_fun(r1[i]-1,c1[i]-1,r2[i]-1,c2[i]-1);//값 이동

        ch_fun(r1[i]-1,c1[i]-1,r2[i]-1,c2[i]-1);//값 변환
    }

    //출력
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0; 
}
