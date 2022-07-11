#include <iostream>
using namespace std;
int main(){
    int n[10];
    int cnt = 0, sum_val = 0, cnt2 = 0;
    for(int i=0;i<10;i++){
        cin >> n[i];
        if(n[i]==0) break;
        cnt ++;
    }
    for(int i=0;i<cnt;i++){
        if(n[i]%2==0){
            sum_val += n[i];
            cnt2 ++;
        }
    }
    cout<<cnt2<<' '<<sum_val;
    return 0;
}
