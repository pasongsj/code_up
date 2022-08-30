#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX_M 100000
#define MAX_NUM (long long)1e14
int arr[MAX_M];
int n, m;

bool is_possible(long long num){
    long long cnt = 0;
    for(int i=0;i<m;i++){
        if(arr[i] == 0) continue;
        cnt += num/arr[i];
    }
    return(cnt>=n);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++)    cin>>arr[i];
    
    long long left = 1, right = MAX_NUM, ans = MAX_NUM;
    while(left<=right){
        long long mid = (left + right)/2;
        bool test  = is_possible(mid);
        if(test){
            ans = min(ans,mid);
            right = mid -1;
        }
        else    left = mid + 1;


    }
    cout<<ans;
    return 0;

}
