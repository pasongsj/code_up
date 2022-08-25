#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;
#define MAX_N 50000

int prefix_sum[MAX_N+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int,int> remain_max;
    unordered_map<int,int> remain_min;

    for(int i=0;i<7;i++){
        remain_max[i] = INT_MIN;
        remain_min[i] = INT_MAX;
    }
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        prefix_sum[i] = (prefix_sum[i-1]+tmp)%7;
        int div7 = prefix_sum[i];
        remain_max[div7] = max(remain_max[div7],i);
        remain_min[div7] = min(remain_min[div7],i);
    }
    int ans= 0;
    for(int i=0;i<7;i++){
        ans = max(ans, remain_max[i]-remain_min[i]);
    }
    cout<<ans;
    return 0;
}
