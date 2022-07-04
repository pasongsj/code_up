#include<iostream>
using namespace std;
int main(){
    int n,tmp, sum_val = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        sum_val += tmp;
    }
    cout<<fixed;
    cout.precision(1);
    cout << sum_val << ' ' << (double)sum_val/n;
    return 0;
}
