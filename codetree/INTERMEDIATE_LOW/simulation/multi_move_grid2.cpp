#include <iostream>
#include <utility>
using namespace std;
int arr[20][20];
int n;
pair<int,int> pos[20*20+1];
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

int find_max(pair<int,int> cur){
    int x = cur.first;
    int y = cur.second;
    int ans;
    int max = 0;
    for(int i=0;i<8;i++){
        if(in_range(x+dx[i],y+dy[i])&&max<arr[x+dx[i]][y+dy[i]]){
            max = arr[x+dx[i]][y+dy[i]];
            ans = i;
        }
    }
    return ans;
}

void swap(pair<int,int>cur, pair<int,int>dest){
    int cur_num = arr[cur.first][cur.second];
    int dest_num = arr[dest.first][dest.second];
    pair<int,int> tmp_cur(cur);
    arr[cur.first][cur.second] = dest_num;
    arr[dest.first][dest.second] = cur_num;//2, 0 = tmp
    pos[cur_num] = make_pair(dest.first,dest.second);
    pos[dest_num] = make_pair(tmp_cur.first,tmp_cur.second);
}


int main(){
    int m,dir;
    //입력
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            pos[arr[i][j]] = make_pair(i,j); 
        }
    }

    
    //swap
    pair<int,int>swap_pos;
    for(int j=0;j<m;j++){
        for(int i=1;i<=n*n;i++){
            dir = find_max(pos[i]);
            swap_pos = make_pair(pos[i].first+dx[dir],pos[i].second+dy[dir]);
            swap(pos[i],swap_pos);
        }
    }

    //출력
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<arr[i][j]<<' ';
        cout<<endl;
    }

}
