#include <iostream>

#include <tuple>
#include <vector>
using namespace std;


#define MAX_N 20
#define MAX_M 100

vector<int> arr[MAX_N][MAX_N];
int num[MAX_M];
int n, m;



bool in_range(int x, int y){
    return (0<=x && x<n && 0<=y && y<n);
}

pair<int,int> find_max(pair<int,int> cur){
    int x,y,nx,ny;
    tie(x,y) = cur;
    int max_val = 0;
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    for(int d=0;d<8;d++){
        int tmpx = x+dx[d],tmpy = y+dy[d];
        if(in_range(tmpx,tmpy)){
            for(int i=0;i<arr[tmpx][tmpy].size();i++){
            //    cout<<tmpx<<','<<tmpy<<':'<<max_val<<' ';
                if(arr[tmpx][tmpy][i]>max_val){
                    max_val = arr[tmpx][tmpy][i];
                    nx = tmpx;
                    ny = tmpy;
                }
            }
        }
    }
    if(max_val == 0)    return make_pair(x,y);
   // cout<<endl;
    return make_pair(nx,ny);
}

int find_index(pair<int,int>cur,int point){
    int x,y;
    tie(x,y) = cur;
    for(int i=0;i<arr[x][y].size();i++){
        if(point==arr[x][y][i]) return i;
    }
}
void cpy_pos(pair<int,int>cur, pair<int,int>next, int point){
    int index = find_index(cur,point);
    int cx,cy;
    tie(cx,cy) = cur;
    int nx,ny;
    tie(nx,ny) = next;
    for(int i=index;i<arr[cx][cy].size();i++){
        arr[nx][ny].push_back(arr[cx][cy][i]);
       // cout<<arr[cx][cy][i]<<' ';
    }
   // cout<<endl;
    int cnt = arr[cx][cy].size()-index;
    for(int i=0;i<cnt;i++){
        arr[cx][cy].pop_back();
    }
}

pair<int,int> find_pos(int num){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<arr[i][j].size();k++){
                if(num==arr[i][j][k]){
                  //  cout<<n<<arr[i][j][k]<<endl;
                    return make_pair(i,j);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            arr[i][j].push_back(tmp);
        }
    }
    for(int i=0;i<m;i++){
        cin >> num[i];
    }

    for(int i=0;i<m;i++){
        pair<int,int> cur_pos = find_pos(num[i]);
      //  cout<<"find pos "<<cur_pos.first<<','<<cur_pos.second<<endl;
        pair<int,int> next_pos = find_max(cur_pos);
      //  cout<<"next pos "<<next_pos.first<<','<<next_pos.second<<endl;
        if(cur_pos==next_pos) continue;
        cpy_pos(cur_pos,next_pos,num[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=arr[i][j].size()-1;k>=0;k--){
                cout<<arr[i][j][k]<<' ';
            }
            if(arr[i][j].size()==0)    cout<<"None";
            cout<<endl;
        }
    }

}
