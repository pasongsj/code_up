#include <iostream>
using namespace std;
int main(){
    int n[10];
    int cnt = 0, sum_val = 0;
    for(int i=0;i<10;i++){
        cin >> n[i];
        if(n[i]==0) break;
        cnt ++;
    }
    for(int j=0;j<cnt;j++){
        sum_val += n[j];
    }
    cout<<fixed;
    cout.precision(1);
    cout<< sum_val<<' '<<(double)sum_val/cnt;
    return 0;
}
