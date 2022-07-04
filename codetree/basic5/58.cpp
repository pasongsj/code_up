#include <iostream>
using namespace std;
int main(){
    int n,i,sum_val = 0;
    cin >> n;
    for(i=1;i<=100;i++){
        sum_val += i;
        if(sum_val>=n)  break;
    }
    cout << i;
    return 0;
}
