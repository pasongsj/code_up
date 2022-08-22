#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int>arr;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    
    int L = n-1,cnt = 0;
    for(int i=0;i<n;i++){
        while(i<L && arr[i]+arr[L]>k ){
            L--;
        }
        if(i>=L)    break;
        cnt+=L-i;
    }
    cout<<cnt;
    return 0;
}
