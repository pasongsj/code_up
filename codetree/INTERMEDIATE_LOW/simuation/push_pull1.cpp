#include <iostream>
using namespace std;
int main(){
    int n,t,tmp;
    cin >> n >> t;
    t %= 2*n;
    int arr[2*n];
    for(int i=0;i<2*n;i++)    cin>>arr[i];// 123651 -> 112365
    for(int k=0;k<t;k++){
        tmp = arr[2*n-1];
        for(int i=2*n-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0] = tmp;
    }
    for(int i=0;i<2*n;i++){
        cout<<arr[i]<<' ';
        if(i%n == n-1)    cout<<endl;
    }


    return 0;
}
