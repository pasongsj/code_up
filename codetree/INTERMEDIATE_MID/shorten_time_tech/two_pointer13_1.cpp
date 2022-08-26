#include <iostream>
#include <set>
#include <climits>
#define MAX_N 100000

int arr[MAX_N];
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    set<int> pos;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        pos.insert(x);
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int y, near_before, near_after;
        y = arr[i];
        near_after = *pos.lower_bound(y);

        near_before = *prev(pos.lower_bound(y));

        if(pos.end() == pos.lower_bound(y)){
            near_after = INT_MAX;
        }

        ans = max(ans,min(abs(near_after-y),abs(near_before-y)));
    }
    cout<<ans;
    return 0;

}
