#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,tmp;
    cin >> n;
    int arr[2*n],ans[n];
    for(int i=0;i<n*2;i++)    cin>>arr[i];
    sort(arr,arr+2*n);
    for(int j=0;j<n;j++){
        ans[j] = arr[j] + arr[2*n-j-1];
    }
    sort(ans,ans+n);
    cout<<ans[n-1];
    return 0;
}


