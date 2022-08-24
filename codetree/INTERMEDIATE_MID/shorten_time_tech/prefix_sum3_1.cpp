#include <iostream>
using namespace std;
#define MAX_N 1001
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int arr[MAX_N] = {0};
    int ans[MAX_N] = {0};
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int last = 1;
    int res = 0;
    for(int i=1;i<=n;i++){
        int tmp = ans[i-1]+arr[i];
        if(arr[i] == k){
            ans[i] = 0;
            res++;
        }
        else if(tmp == k){
            ans[i] = tmp-ans[last];
            last++;
            res++;
        }
        else if(tmp<k){
            ans[i] = tmp;
            continue;
        }   
        if(tmp>k){
            ans[i] = ans[i-1]-ans[last];
            last++;
        }
    }
    cout<<res;
    return 0;
}
