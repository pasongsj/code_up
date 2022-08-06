#include <iostream>
#include <climits>
#include <utility>
using namespace std;

#define MAX_N 100
pair<int,int> point[MAX_N];
int n;
int find_len(int pos){
    int cnt = 0;
    pair<int,int> start = point[0];
    for(int i=1;i<n;i++){
        if(i == pos)    continue;
        cnt += abs(point[i].first-start.first) + abs(point[i].second-start.second);
        start = point[i];
    }
    return cnt;
}

int main(){
    int ans = INT_MAX;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> point[i].first >> point[i].second;
    }
    for(int i=1;i<n-1;i++){
        ans = min(ans,find_len(i));
    }
    cout<<ans;
    return 0;
}
