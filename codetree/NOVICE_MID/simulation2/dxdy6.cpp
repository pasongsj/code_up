#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m,x=0,y=0,cnt = 0;
    cin >> n;
    char dir;
    
    map<char,int>dx = {{'W', 0}, {'S', 1}, {'N', -1}, {'E', 0}};
    map<char,int>dy = {{'W', -1}, {'S', 0}, {'N', 0}, {'E', 1}};

    for(int i=0;i<n;i++){
        cin >> dir >> m;
        for(int j=0;j<m;j++){
            x += dx[dir];
            y += dy[dir];
            cnt ++;
            if(x == 0&& y == 0){
                cout<<cnt;
                return 0;
            }
        }
    }
    cout<< -1;
    return 0;
}
