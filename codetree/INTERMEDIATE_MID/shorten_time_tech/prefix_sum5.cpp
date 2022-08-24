#include <iostream>
#include <climits>
using namespace std;

#define MAX_N 100001
int sub_arr[MAX_N];
int arr[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,b;
    cin >> n >> k >> b;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sub_arr[tmp] = 1;
    }
    for(int i=1;i<=n;i++){
        arr[i]= arr[i-1]+sub_arr[i];
    }

    int ans = INT_MAX;
    for(int i=k;i<=n;i++){
        ans = min(ans,arr[i]-arr[i-k]);
    }
    cout<<ans;

    return 0;
}
