#include <iostream>
using namespace std;
#define MAX_N 1001

int arr[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        arr[i] = arr[i-1] + tmp;
    }
    int R = 1,ans = 0;
    for(int i=0;i<=n;i++){
        while(arr[R] - arr[i]<k && R<=n){
            R++;
        }
        if(R==n+1)  break;
        if(arr[R]-arr[i] == k)  ans++;
    }
    cout<<ans;
    return 0;
}
