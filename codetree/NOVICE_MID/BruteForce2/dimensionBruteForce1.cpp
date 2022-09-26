#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> point;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        point.push_back(make_pair(x,y));
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){//제외 점
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN ,max_y = INT_MIN;
        for(int j=0;j<n;j++){
            if(i==j)    continue;
            int cur_x, cur_y;
            tie(cur_x,cur_y) = point[j];
            min_x = min(min_x,cur_x);
            max_x = max(max_x,cur_x);
            min_y = min(min_y,cur_y);
            max_y = max(max_y,cur_y);
        }
        ans = min(ans,(max_x-min_x) * (max_y-min_y));
    }
    cout<<ans;
}
