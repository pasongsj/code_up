#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define MAX_N 100001

int arr[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = 0, L = 1;

    unordered_set<int> sec;
    for(int i=1;i<=n;i++){
        while(L<=n && sec.find(arr[L])==sec.end()){
            sec.insert(arr[L++]);
        }
        ans = max(ans,L-i);
        sec.erase(arr[i]);
    }
    cout<<ans;
    return 0;
}
