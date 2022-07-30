#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 1000
int arr[MAX_N];
int cnt[MAX_N];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        cnt[i] = INT_MIN;
    }
    arr[0] = 0;
    cnt[0] = 0;
    int max_val = 0,point = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                cnt[i] = max(cnt[i],cnt[j]+1);

            }
        }
        max_val = max(max_val,cnt[i]);
    }

    cout<<max_val;
    return 0;

}
