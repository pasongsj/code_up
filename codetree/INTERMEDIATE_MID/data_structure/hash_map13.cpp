#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 1000

int arr[MAX_N];
int main(){
    int n,k;
    cin >> n >> k;
    
    unordered_map<int,int> count;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        count[arr[i]]++;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        count[arr[i]]--;
        for(int j=0;j<i;j++){
            int tmp = k-arr[i]-arr[j];
            cnt += count[tmp];
        }
    }
    cout<<cnt;
    return 0;

}
