#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10001
int arr[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int sum = 0,cnt = 0,L = 1;
    for(int i=1;i<=n;i++){
        while(L<=n && sum<m){
            sum+=arr[L++];
        }
        if(sum == m)    cnt++;
        sum -=arr[i];
    }
    cout<<cnt;
    return 0;
}

