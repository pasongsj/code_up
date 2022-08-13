#include <iostream>
#include <climits>
using namespace std;
int sum = 0,n = 6;

int diff(int a,int b,int c){
    return abs(sum-(a+b+c)*2);
}
int main(){
    int arr[6];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans = min(ans,diff(arr[i],arr[j],arr[k]));
            }
        }
    }
    cout<<ans;
    return 0;
}
