#include <iostream>
using namespace std;

#define MAX_N 10
int arr[MAX_N];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long k,ans = 0;
    cin >> n >> k;

    for(int i=0;i<n;i++)    cin>>arr[i];

    for(int i=n-1;i>=0;i--){
        ans += (k/arr[i]);
        k %= arr[i];
    }
    cout<<ans;
    return 0;
}
