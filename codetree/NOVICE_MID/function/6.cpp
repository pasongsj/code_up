#include <iostream>
using namespace std;
int SUM(int a) {
    int sum_val = 0;
    for(int i=1;i<a+1;i++)  sum_val += i;
    return sum_val/10;
}
int main(){
    int result ,n;
    cin >> n;
    result = SUM(n);
    cout<< result;
    return 0;
}
