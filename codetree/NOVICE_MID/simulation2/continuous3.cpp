#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n, cur, cnt = 0,ans = 0, before = INT_MIN;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cur;
        if(cur > before)    cnt++;
        else    cnt = 1;
        before = cur;
        ans = max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
