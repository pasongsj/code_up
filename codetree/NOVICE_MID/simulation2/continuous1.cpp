#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 1000
int arr[MAX_N];

int main(){
    int n,cnt,num,ans;
    cin >> n;
    num = INT_MIN;
    cnt = 1;
    ans = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(num==arr[i])  cnt++;
        else{
            cnt = 1;
            num = arr[i];
        }
        ans = max(ans,cnt);
    }
    cout<<ans;
    return 0;

}
