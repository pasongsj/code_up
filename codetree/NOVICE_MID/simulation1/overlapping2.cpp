#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_RANGE 201

int main(){
    int n,x1,x2;
    int arr[MAX_RANGE]={};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> x2;
        for(int j=x1;j<x2;j++){
            arr[j+100]++;
        }
    }
    sort(arr,arr+MAX_RANGE,greater<int>());

    cout<<arr[0];
    return 0;
}
