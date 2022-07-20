#include <iostream>
#include <string>
using namespace std;
int main(){
    int dx[4] = {1, 0, -1, 0}; // 동 남 서 북 
    int dy[4] = {0, -1, 0, 1}; // 동->북, 북->서, 서->남, 남->동/ 0 3, 3 2, 2 1, 1 0 L
    int x=0,y=0, dir = 3;
    string s;
    cin >> s;
    for(int i=0; i<s.length();i++){
        if(s[i]=='L')   dir = (dir+3)%4;
        else if(s[i]=='R')  dir = (dir+1)%4;
        else{
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout<< x <<' '<< y<<endl;
    return 0;
}

