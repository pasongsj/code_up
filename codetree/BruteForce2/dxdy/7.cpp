#include <iostream>
#include <string>
using namespace std;
int main(){
    int dir = 0,x = 0,y = 0,cnt = 0;
    string s;
    cin >> s;
    int dx[4] = {-1,0,1,0};//북 서 남 동
    int dy[4] = {0,-1,0,1};

    for (int i=0;i<s.length();i++){
        if(s[i] == 'F'){
            x += dx[dir];
            y += dy[dir];
        }
        else if(s[i] == 'L'){
            dir = (dir+1)%4;
        }
        else{
            dir = (dir+3)%4;
        }
        cnt ++;
        if(x==0 && y==0 && i!=0){
            cout<<cnt;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
