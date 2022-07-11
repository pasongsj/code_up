#include <iostream>
using namespace std;
int main(){
    int n,cnt = 0,val = 1;
    cin >> n;
    while(cnt<2){
        if((n*val)%5==0){
            cnt++;
        }
        cout<<n*val<<' ';
        val++;
    }
    return 0;
}
