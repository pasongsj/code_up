#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    vector<pair<int,int>> point;
    cin >> n;

    for(int i=0;i<n;i++){
        int s,e;
        cin >> s >> e;
        point.push_back(make_pair(s,+1));
        point.push_back(make_pair(e+1,-1));
    }
    sort(point.begin(),point.end());

    int ans = 0, cnt = 0;
    for(int i=0;i<point.size();i++){
        int room;
        tie(ignore,room) = point[i];
        cnt += room;
        ans = max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
