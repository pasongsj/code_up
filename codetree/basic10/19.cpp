#include <iostream>
using namespace std;
void Modify(int *x,int m){
    for(int i=0;i<m;i++){
        if(*(x+i)%2==0)   *(x+i) /= 2;
        cout<<*(x+i)<<' ';
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    Modify(arr,n);
    return 0;
}
