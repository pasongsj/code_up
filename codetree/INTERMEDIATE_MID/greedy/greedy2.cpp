#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100000

int arr[MAX_N+1];
int main(){
    int n, ans = INT_MAX+1000;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum = max(arr[i],sum+arr[i]);
        ans = max(ans,sum);
    }
    cout<<ans;
}
