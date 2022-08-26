#include <iostream>
#define MAX_N 100000
using namespace std;

int arr[MAX_N];
int n,m;

int upper_bound(int target){
    int min_idx = n, left = 0, right = n-1;
    while(left<=right){
        int mid =  (left + right)/2;
        if(arr[mid]>target){
            min_idx = min(min_idx,mid);
            right = mid-1;
        }
        else    left = mid+1;
    }
    return min_idx;

}
int lower_bound(int target){
    int min_idx = n, left = 0, right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]>=target){
            min_idx = min(min_idx,mid);
            right = mid-1;
        }
        else    left = mid+1;
    }
    return min_idx;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        cout<<upper_bound(tmp)-lower_bound(tmp)<<'\n';
    }
    return 0;
}
