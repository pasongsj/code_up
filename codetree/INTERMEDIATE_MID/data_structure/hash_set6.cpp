#include <iostream>
#include <unordered_set>
#include <unordered_map>
#define MAX_N 100001

using namespace std;
int arr[MAX_N],a[MAX_N],b[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    unordered_set<int> ans[MAX_N];

    for(int i=1;i<=n;i++){
        arr[i] = i;
        ans[i].insert(i);
    }
    for(int i=0;i<k;i++){
        cin >> a[i] >> b[i];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<k;j++){
            int tmp;
            ans[arr[a[j]]].insert(b[j]);
            ans[arr[b[j]]].insert(a[j]);

            tmp = arr[a[j]];
            arr[a[j]] = arr[b[j]];
            arr[b[j]] = tmp;
        }
    }

    for(int i=1;i<=n;i++)   cout<<ans[i].size()<<'\n';

    return 0;
}

