#include <iostream>
#include <vector>
using namespace std;

vector<int> stack[1001]; // 최대n 
bool visited[1001]; //n

void dfs(int ver){
    for(int i=0;i<(int)stack[ver].size();i++){
        if(visited[stack[ver][i]] == false){
            visited[stack[ver][i]] = true;
            dfs(stack[ver][i]);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int v1,v2;
    for(int i=0;i<m;i++){
        cin >> v1 >> v2;
        stack[v1].push_back(v2);
        stack[v2].push_back(v1);
    }
    int start_point = 1;
    visited[1] = true;
    dfs(start_point);
    int ans = 0;
    for(int i=2;i<1001;i++){
        if(visited[i])  ans++;
    }
    cout<<ans;
    return 0;
}
