#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100

int main(){
    int n, k, ans = INT_MIN;
    cin >> n >> k;
    int arr[MAX_N] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n-k+1;i++){
        int tmp = 0;
        for(int j=i;j<i+k;j++){
            tmp += arr[j];
        }
        ans = max(ans,tmp);
    }
    cout<<ans;
    return 0;
}
