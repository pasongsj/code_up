#include <iostream>
using namespace std;
int main(){
    int n,m,k,cnt = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> k;
        if(m==k)    cnt++;
    }
    cout<< cnt;
    return 0;
}
