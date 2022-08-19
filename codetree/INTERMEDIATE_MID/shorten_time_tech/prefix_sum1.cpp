#include <iostream>
using namespace std;
#define MAX_N 100001
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int ans[MAX_N] = {0};

    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        ans[i] = ans[i-1]+tmp;
    }
    int res = 0;
    for(int i=k;i<n;i++){
        res = max(res,ans[i]-ans[i-k]);
    }
    cout<<res;
    return 0;
}
