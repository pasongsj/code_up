#include <iostream>
#include <climits>
using namespace std;

int f(int n,int max_v){
    return(n>max_v?n:max_v);
}
int main(){
    int n,max_val = INT_MIN;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int j=0;j<n;j++){
        max_val = f(arr[j],max_val);
    }
    cout <<max_val;
    return 0;
}

