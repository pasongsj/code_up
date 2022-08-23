#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int arr[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = n+1, cnt = 0, L = 0;
    for(int i=0;i<n;i++){
        while(L<n && cnt<k){
            if(arr[L] == 1)   cnt++;
            L++;
        }
        if(cnt<k)   break;
        ans = min(ans, L-i);
        if(arr[i]==1)   cnt--;
    }
    if(ans == n+1)  cout<<-1;
    else    cout<<ans;

    return 0;

}
