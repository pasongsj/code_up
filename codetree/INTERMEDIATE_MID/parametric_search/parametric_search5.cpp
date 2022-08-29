#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 200000

int arr[MAX_N];
int n, m;

bool is_posssible(int num){
    int cnt = 1, x = 1, before = arr[0];
    while(x<n){
        if(arr[x]-before>=num){
            cnt++;
            before = arr[x];
        }
        x++;
    }
    return cnt>=m;
}

int max_len(){
    int left = 1, right = arr[n-1],num = 0;
    while(left<=right){
        int mid = (left + right)/2;
        if(is_posssible(mid)){
            left = mid + 1;
            num = max(num,mid);
        }
        else{
            right = mid - 1;
        }
    }
    return num;

}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);

    cout<<max_len();

    return 0;
}
