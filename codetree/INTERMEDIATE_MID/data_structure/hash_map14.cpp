#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_N 1000
int arr[MAX_N];

int main(){
    int n,k;
    cin >> n >> k;

    unordered_map <int,int> count;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        count[arr[i]]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tmp = k-arr[i]-arr[j];
            ans += count[tmp];
            if(arr[i] == tmp)   ans--;
            if(arr[j] == tmp)   ans--;
        }
    }
    cout<<ans/3;
    return 0;
}
