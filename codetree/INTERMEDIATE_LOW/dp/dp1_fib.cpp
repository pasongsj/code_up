#include <iostream>
using namespace std;
#define MAX_N 45


int main(){
    int n;
    cin >> n;
    int arr[MAX_N];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout<<arr[n-1];
    return 0;
}
