#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100
int main(){
    int n,tmp,ans = INT_MIN;
    cin >> n;
    int arr[MAX_N] = {0};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        tmp = 0;
        for(int j=i+2;j<n;j++){
            tmp = arr[i] + arr[j];
            ans = max(ans,tmp);
        }
    }
    cout<<ans;
    return 0;
}
