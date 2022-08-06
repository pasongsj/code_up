#include <iostream>
#include <climits>
#define MAX_N 100
using namespace std;

int main(){
    int ans = INT_MAX;
    int n;
    int arr[MAX_N] = {0};
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        int tmp = 0;
        for(int j=0;j<n;j++){
            if(i==j)    continue;
            tmp += abs(i-j)*arr[j];
        }
        ans = min(ans,tmp);
    }
    cout<<ans;
    return 0;
}
