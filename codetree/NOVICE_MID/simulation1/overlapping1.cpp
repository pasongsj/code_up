#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k,a,b;
    cin >> n >> k;
    int arr[n] = {};
    
    for(int i=0;i<k;i++){
        cin >> a >> b;
        for(int j=a;j<=b;j++)   arr[j] = arr[j]+1;
    }
    sort(arr,arr+n,greater<int>());
    cout<<arr[0];
    return 0;
}

