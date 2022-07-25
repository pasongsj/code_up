#include <iostream>
#include <map>
using namespace std;

int arr[50][50];
int dir[50][50];
int ch_arr[50][50];
int ch_dir[50][50];
int n;

map<char,int> way = {{'U',1},{'L',2},{'R',3},{'D',4}};

bool in_range(int a,int b){
    return (0<=a && a<n && 0<=b && b<n);
}

void mov(){
    int d;
    int dx[5] = {0,-1,0,0,1};//1234
    int dy[5] = {0,0,-1,1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                d = dir[i][j];
                if(!in_range(i+dx[d],j+dy[d])){
                    d = 5-d;
                    ch_arr[i][j]++;
                    ch_dir[i][j] = d;
                }
                else{
                    ch_arr[i+dx[d]][j+dy[d]]++;
                    ch_dir[i+dx[d]][j+dy[d]] = d;
                }
            }
        }
    }
}
void dup(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch_arr[i][j]>1){
                arr[i][j] = 0;
                dir[i][j] = 0;
            }
            else{
                arr[i][j] = ch_arr[i][j];
                dir[i][j] = ch_dir[i][j];
            }
            ch_arr[i][j] = 0;
            ch_dir[i][j] = 0;
        }
    }
}

int main(){
    int t, m;
    cin >> t;
    int x,y,d;
    char direct;
    for(int i=0;i<t;i++){
        cin >> n >> m;
        int time = 0,lim = 3*n;
        //입력
        for(int j=0;j<m;j++){
            cin >> x >> y >> direct;
            x--;
            y--;
            d = way[direct];
            arr[x][y] = 1;
            dir[x][y] = d;
        }
        //이동,삭제
        while(time<lim){
            mov();
            dup();
            time++;
        }
        //출력
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)    ans+=arr[i][j];
        }
        cout<<ans<<endl;
        //초기화
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = 0;
                dir[i][j] = 0;
            }
        }
    }
    

    return 0;
    

}
