#include <iostream>
using namespace std;
#define MAX_N 100
int main(){
    int n,ans = 0;
    int arr[MAX_N] = {0};
    cin >> n;
    for(int i=0;i<n;i++)    cin>>arr[i];

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]<=arr[j]&&arr[j]<=arr[k])    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
