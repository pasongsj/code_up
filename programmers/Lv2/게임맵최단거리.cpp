#include<vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


bool in_range(int a, int b,int n,int m){
    return 0<=a && a<n && 0<=b && b<m;
}

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    int dx[4] ={1,-1,0,0}, dy[4] = {0,0,1,-1};
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,1));
    
    int n = maps.size(), m = maps[0].size();
    while(!q.empty()){
        int cx,cy,ans;
        tie(cx,cy,ans) = q.front();
        q.pop();
        if(cx == n-1 && cy == m-1)  return ans;
        for(int i=0;i<4;i++){
            int nx = cx+dx[i], ny = cy+dy[i];
            if(in_range(nx,ny,n,m) && maps[nx][ny] == 1){
                maps[nx][ny] = 0;
                answer ++;
                q.push(make_tuple(nx,ny,ans+1));
            }
        }
    }
    return -1;
}
