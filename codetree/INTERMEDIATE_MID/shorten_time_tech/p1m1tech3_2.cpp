#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<pair<int, int>> point;
    cin >> n;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        point.push_back(make_pair(x,1));
        point.push_back(make_pair(y,-1));

    }
    sort(point.begin(),point.end());

    int ans = 0,tmp = 0;;
    for(int i=0;i<point.size();i++){
        tmp += point[i].second;
        ans = max(ans, tmp);
    }
    cout<<ans;
    return 0;
}


