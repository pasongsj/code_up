#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> link[201];
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j]) link[i].push_back(j);
        }
    }
    bool visited[201] = {false};
    for(int i=0;i<n;i++){
        if(visited[i])  continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int c = q.front();
            visited[c] = true;
            q.pop();
            for(int j=0;j<link[c].size();j++){
                if(visited[link[c][j]]) continue;
                q.push(link[c][j]);
            }
        }
        answer++;
        
    }
    return answer;
}

