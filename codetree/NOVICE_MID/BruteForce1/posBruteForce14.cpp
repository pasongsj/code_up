

#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;
#define MAX_NM 50

int n, m;
char arr[MAX_NM][MAX_NM];
vector<pair<int,int>> pos_L;

bool in_range(int a1, int b1, int a2, int b2){
    return(0<=a1 && 0<=b1 && 0<=a2 && 0<=b2 && a1<n && a2<n && b1<m && b2<m);
}

int is_LEE(pair<int,int> cur){
    int tmp = 0;
    int dx[8] = {0,-1,-1,-1,0,1,1,1};
    int dy[8] = {-1,-1,0,1,1,1,0,-1};
    for(int i=0;i<8;i++){
        int x1 = cur.first + dx[i], y1 = cur.second + dy[i];
        int x2 = cur.first + 2*dx[i], y2 = cur.second + 2*dy[i];
        if(in_range(x1,y1,x2,y2)&& arr[x1][y1] == 'E' && arr[x2][y2] == 'E')    tmp++;
    }
    return tmp;
}

int main(){
    string s;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            arr[i][j] = s[j];
            if(arr[i][j]=='L'){
                pos_L.push_back(make_pair(i,j));
            }
        }
    }


    int ans = 0;
    for(int i=0;i<pos_L.size();i++){
        ans += is_LEE(pos_L[i]);
    }
    cout<<ans;
    return 0;
}
