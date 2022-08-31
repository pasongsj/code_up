#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 100000



int arr[MAX_N];
int n, m;
bool is_possible(int num){
    int cnt = 1, tmp = 0;
    for(int i=0;i<n;i++){
        if(num<arr[i])  return false;
        if(tmp+arr[i]>num){
            cnt ++;
            tmp = arr[i];
        }
        else    tmp += arr[i];
    }
    return(cnt<=m);
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int left = 1, right = INT_MAX, ans = INT_MAX;
    while(left <= right){
        int mid = (left + right)/2;
        if(is_possible(mid)){
            right = mid-1;
            ans = min(ans,mid);
        }
        else{
            left = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
