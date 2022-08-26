#include <iostream>
#define MAX_N 100000
using namespace std;

long long int arr[MAX_N];
int n,m;

int find_index(long long int num){
    int left = 0, right = n-1;
    while(left<=right){
        int mid = (left + right)/2;
        if(arr[mid] == num) return mid+1;
        if(arr[mid]<num){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        long long int tmp;
        cin >> tmp;
        cout<<find_index(tmp)<<'\n';
    }
    return 0;
}
