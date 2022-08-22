#include <iostream>
using namespace std;
#define MAX_N 100001

int arr[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int L=1,ans = n+1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        while(L<=n && sum < s){
            sum += arr[L++];
        }
        if(sum<s)   break;
        ans = min(L-i+1,ans);
        sum -= arr[i];
    }
    if(ans == n+1)  cout<<-1;
    else    cout<<ans;
    return 0;

}
