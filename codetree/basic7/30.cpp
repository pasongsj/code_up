#include <iostream>
using namespace std;
int main(){
    int i, n,m, cnt = 0;
    cin >> n;
    for(i=0;i<n;i++){
        cin>>m;
        if(m==2)    cnt++;
        if(cnt==3)  break;
    }
    cout<< i+1;
    return 0;
}
