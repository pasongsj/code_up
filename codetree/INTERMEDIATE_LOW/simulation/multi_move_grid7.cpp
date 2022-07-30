#include <iostream>
#include <map>
using namespace std;
#define MAX_N 50

class Bead{
    public:
        int w;
        int d;
        int num;
        Bead(int w = 0,int d = -1, int num = 0){
            this->w = w;// 구슬의 무게
            this->d = d;// 구슬 이동 방향
            this->num = num;// 구슬 번호
        }
};

Bead arr[MAX_N][MAX_N];
Bead ch_arr[MAX_N][MAX_N];
int n,m,t;

bool in_range(int a, int b){
    return(0<=a && a<n && 0<=b && b<n);
}

void mov(){
    int dx[4] = {-1,0,0,1};// U L R D
    int dy[4] = {0,-1,1,0};
    int dir,tmp_num;
    int n_x,n_y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dir = arr[i][j].d;
            if(dir<0)   continue;
            n_x = i+dx[dir];
            n_y = j+dy[dir];
            if(!in_range(n_x,n_y)){
                arr[i][j].d = 3-arr[i][j].d;
                n_x = i,n_y = j;
            }
            Bead tmp = arr[i][j].num > ch_arr[n_x][n_y].num ? arr[i][j] : ch_arr[n_x][n_y];
            ch_arr[n_x][n_y].w += arr[i][j].w;
            ch_arr[n_x][n_y].d = tmp.d;
            ch_arr[n_x][n_y].num = tmp.num;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = ch_arr[i][j];
            Bead tmp_init;
            ch_arr[i][j] = tmp_init;
        }
    }
}

int main(){
    cin >> n >> m >> t;
    int r,c,w;
    char d;
    map<char,int> dir = {{'U',0},{'L',1}, {'R',2}, {'D',3}};// U L R D
    
    for(int i=0;i<m;i++){
        cin >> r >> c >> d >> w;
        arr[--r][--c] = Bead(w,dir[d],i+1);
    }
    while(t--){
        mov();
    }
    int cnt=0,max_w=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j].w>0)   cnt++;
            if(arr[i][j].w > max_w) max_w = arr[i][j].w;
        }
    }
    cout<< cnt <<' '<< max_w;
    return 0;

}