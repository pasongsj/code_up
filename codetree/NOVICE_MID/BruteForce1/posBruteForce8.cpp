#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 1004
int main(){
    int n, tmp, ans = INT_MAX;
    int arr[MAX_N] = {0};
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){// 시작점 i
        tmp = 0;
        for(int j=1;j<=n;j++){
            if(j-i<0)   tmp += arr[j]*(n-i+j);
            else    tmp += arr[j]*(j-i);
        }
        ans = min(tmp,ans);
    }
    cout << ans;
    return 0;
}
