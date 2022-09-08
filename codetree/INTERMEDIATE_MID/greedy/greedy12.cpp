#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int,int>> rooms;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        rooms.push_back(make_pair(e,s));
    }

    sort(rooms.begin(),rooms.end());
    int L = rooms[0].first, ans = 0;
    for(int i=1;i<n;i++){
        if(rooms[i].second >= L){
            L = rooms[i].first;
        }
        else    ans++;
    }
    cout<<ans;
    return 0;
}
