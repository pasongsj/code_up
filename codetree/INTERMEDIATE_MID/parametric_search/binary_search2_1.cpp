#include <iostream>
#define MAX_N 100000
using namespace std;

int arr[MAX_N];
int n,m;

int find_index(int num){
    int left = 0, right = n-1;
    int ans = n;
    while(left<=right){
        int mid = (left + right)/2;
        if(arr[mid]<num){
            left = mid+1;
        }
        else{
            ans = min(ans,mid);
            right = mid-1;
        }
    }
    return ans;
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
        cout<<find_index(tmp+1)-find_index(tmp)<<'\n';
    }
    return 0;
}
