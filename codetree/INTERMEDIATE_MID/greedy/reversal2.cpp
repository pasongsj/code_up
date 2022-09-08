#include <iostream>
using namespace std;
#define MAX_N 100

int arr[MAX_N];
int n;
void flip(int index){
    if(index<0||index>=n)   return;
    for(int i=index-1;i<=index+1;i++){
        if(i<0||i>=n)   continue;
        if(arr[i] == 1) arr[i] = 0;
        else    arr[i] = 1;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            flip(i+1);
            ans++;
        }
    }
    if(arr[n-1]==1)    cout<<ans;
    else    cout<<-1;
    return 0;
}
