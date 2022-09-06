#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

long long arr[MAX_N];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int L = 0;
    long long next = arr[0];
    for(int i=0;i<n;i++){
        if(L<=i){
            L = i+1;
            next = arr[i];
        }
        while( L < n && arr[i] < arr[L+1]){
            next = max(next, arr[++L]);
        }
        ans = max(ans, next-arr[i]);
    }
    cout<<ans;
    return 0;
}
