#include<iostream>
using namespace std;
int main(){
    int n, sum_val=0, cnt = 0;
    for(int i=0;i<10;i++){
        cin >> n;
        if(0 <= n && n <= 200){
            sum_val += n;
            cnt ++;
        }
    }
    cout<<fixed;
    cout.precision(1);
    cout << sum_val << ' ' << (double)sum_val/cnt;
    return 0;
}
