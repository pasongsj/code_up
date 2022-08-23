#include <iostream>
using namespace std;
#define MAX_N 100000

int arr[MAX_N], arrB[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        cin >> arrB[i];
    }
    int L = 0;
    bool is_seq = true;
    for(int i=0;i<m;i++){
        while(arrB[i] != arr[L] && L<n){
            L++;
        }
        
        if(L == n){
            is_seq = false;
            break;
        }
        L++;
    }
    if(is_seq)  cout<<"Yes";
    else    cout<<"No";
    return 0;

}
