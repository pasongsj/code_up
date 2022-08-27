#include <iostream>
using namespace std;
#define MAX_N 100000

int arr[MAX_N];
int n,m;
int Find(int num){
    int idx = n, left = 0, right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(num <= arr[mid]){
            idx = min(idx, mid);
            right = mid -1;
        }
        else    left = mid+1;
    }
    return idx;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        int x,idx;
        cin >> x;
        idx = Find(x);
        if(arr[idx] != x)    cout<<-1<<'\n';
        else cout<<idx+1<<'\n';
    }
    return 0;
}
