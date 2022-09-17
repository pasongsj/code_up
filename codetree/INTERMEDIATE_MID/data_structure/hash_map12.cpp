#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX_N 100000

int arr[MAX_N];
int main(){
    int n, k;
    cin >> n >> k;

    unordered_map <int,int> ans;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        ans[arr[i]]++;
    }

    int cnt = 0;

    for(int i=0;i<n;i++){
        cnt += ans[k-arr[i]];
        if(arr[i]*2 == k)   cnt--;//본인 제거
    }

    cout<<cnt/2;

    return 0;
}
