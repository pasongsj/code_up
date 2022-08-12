#include <iostream>
using namespace std;
#define MAX_K 201

int arr[MAX_K];

int main(){
    int n, k, candy, pos, ans = 0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> candy >> pos;
        arr[pos] += candy;
    }
    for(int c=k+1;c<=MAX_K;c++){
        int tmp = 0;
        for(int j=c-k;j<=(c+k > MAX_K-1 ? MAX_K-1 : c+k);j++){
            tmp += arr[j];
        }
        ans = max(ans,tmp);
    }
    cout<<ans;
    return 0;
}

