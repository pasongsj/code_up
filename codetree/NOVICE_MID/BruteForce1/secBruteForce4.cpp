#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NM 100
int arrA[MAX_NM];
int arrB[MAX_NM];
int n,m;

bool is_beuti(int a){

    int tmp[m]; 
    for(int i=a;i<a+m;i++){
        tmp[i-a] = arrA[i];
    }
    sort(tmp,tmp+m);
    for(int i=0;i<m;i++){
        if(arrB[i]!=tmp[i]) return false;
    }
    return true;
}


int main(){
    int tmp, ans = 0;
    cin >> n >> m;

    for(int i=0;i<n;i++)    cin>>arrA[i];
    for(int i=0;i<m;i++)    cin>>arrB[i];
    sort(arrB,arrB+m);
    for(int i=0;i<=n-m;i++){
        if(is_beuti(i)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
