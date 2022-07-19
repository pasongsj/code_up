#include <iostream>
using namespace std;

bool in_range(int a,int b,int m){
    return (0<=a && a<m && 0<=b && b<m);
}

int GetDir(char a) {
    if(a == 'R')
        return 0;
    else if(a == 'D')
        return 1;
    else if(a == 'U')
        return 2;
    else
        return 3;
}

int main(){
    int dx[4] = {0, 1, -1, 0};// R D U L
    int dy[4] = {1, 0, 0, -1};

    int n,t;
    cin >> n >> t;
    int r,c,dir;
    char d;
    cin >> r >> c >> d;
    dir = GetDir(d);
    for(int i=0;i<t;i++){
        if(!in_range(r+dx[dir]-1,c+dy[dir]-1,n))    dir = 3-dir;
        else{
            r += dx[dir];
            c += dy[dir];
        }
    }
    cout<< r <<' '<< c;
    return 0;

}
