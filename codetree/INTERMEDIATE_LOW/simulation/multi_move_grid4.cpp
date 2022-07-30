#include <iostream>
#include <utility>

using namespace std;
int arr[20][20];
pair<int,int> pos[401];
int n;

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

bool in_range(int a, int b){
    return (0<=a && a<n && 0<=b && b<n);
}

int find_max(pair<int,int> cur){
    int x = cur.first, y = cur.second, max = 0, dir;
    for(int i=0;i<8;i++){
        if(in_range(x+dx[i],y+dy[i])&& arr[x+dx[i]][y+dy[i]] > max){
            max = arr[x+dx[i]][y+dy[i]];
            dir = i;
        }
    }
    if(max == 0){
        dir = -1;
    }
    return dir;
}

int main(){
    int m,point,max,dir;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            pos[arr[i][j]] = make_pair(i,j);
        }
    }

    int max1,max2;
    for(int i=0;i<m;i++){
        cin >> point;
        dir = find_max(pos[point]);
     //   cout<<"dir = "<<dir<<endl;
        //x pos[point].first y pos[point].second
        //arr 바꾸기
        pair<int,int>tmp(pos[point]);
        
        //포인트 이동
        pos[point] = make_pair(pos[point].first+dx[dir],pos[point].second+dy[dir]);
        // mov
        max1 = 0,max2=0;
        for(int j=1;j<=n*n;j++){
            if(pos[j] == tmp && j != point && j>max){
                max1 = j;
            }
            if(pos[j]== pos[point] &&j>max){
                max2 = j;
            }
        }
      //  cout<<point<<endl<<pos[point].first<<','<<pos[point].second<<endl;

        arr[tmp.first][tmp.second] = max1;
        arr[pos[point].first][pos[point].second] = max2;
        // for(int j=0;j<n;j++){
        //     for(int k=0;k<n;k++)    cout<<arr[j][k]<<' ';
        //     cout<<endl;
        // }
        // cout<<endl;
    
    }
    for(int k=1;k<=n*n;k++){
        cout<<k<<':'<<pos[k].first<<','<<pos[k].second<<endl;
    }

}
