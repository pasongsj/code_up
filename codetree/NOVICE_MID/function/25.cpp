#include <iostream>
using namespace std;

int arr[100];

int f(int m){
    int cnt = 0;
    while(m>0){
        cnt += arr[m-1];
        if(m % 2 == 0)  m/=2;
        else    m-=1;
    }
    return cnt;
}


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout<< f(m);
    return 0;
}
