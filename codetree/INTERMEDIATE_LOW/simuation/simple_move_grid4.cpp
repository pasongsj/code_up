#include <iostream>
#include <map>
using namespace std;
int arr[100][100];

pair<int,int> point;
int n;

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}
//0 - S, 2||6 - C, -1L, 1R ,-3U 3D
int die[3] = {2,4,5};
void mov(char dir){

    int dx[6] = {0,-1,0,1,1,0};  //LUSCDR
    int dy[6] = {-1,0,0,1,0,1};
    map<int,char> d={
        {'L',0},
        {'U',1},
        {'S',2},
        {'C',3},
        {'D',4},
        {'R',5}
    };
    int tmpd = d[dir];
    int tmpx = point.first + dx[tmpd];
    int tmpy = point.second + dy[tmpd];

    if(!in_range(tmpx,tmpy))    return;
    else{
        point.first = tmpx;
        point.second = tmpy;
        for(int i=0;i<3;i++){
            if(die[i]==2){
                die[i] = tmpd;
            }
            else if(die[i]==3){
                die[i] = 5-tmpd;
            }
            else if(die[i] + tmpd==5){
                die[i] = 2;//S
            }
            else if(die[i] == tmpd){
                die[i] = 3;
            }
        }
    }
    for(int i=0;i<3;i++){
        if(die[i]==2){
            arr[point.first][point.second] = 7-(i+1);
            break;
        }
        else if(die[i]==3){
            arr[point.first][point.second] = i+1;
            break;
        }
    }
}

int main(){
    
    int m,r,c;
    cin >> n >> m >> r >> c;
    char dir;
    arr[--r][--c] = 6;
    point = make_pair(r, c);
    for(int i=0;i<m;i++){
        cin >> dir;
        mov(dir);
    }
    //cout<<endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    ans += arr[i][j];
    }
    cout<<ans;
    return 0;

}
