#include <iostream>
using namespace std;
int main(){
    int n[10];
    int cnt = 0;
    for(int i=0;i<10;i++){
        cin >> n[i];
        if(n[i]==0) break;
        cnt ++;
    }
    for(int i=cnt-1;i>=0;i--){
        cout << n[i]<<' ';
    }
    return 0;
}
