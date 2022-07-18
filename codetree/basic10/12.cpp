#include <iostream>
using namespace std;
int cal_pow(int a, int b){
    int ans = 1;
    for(int i=0; i<b;i++)   ans *= a;
    return ans;
}
int main(){
    int a,b,result;
    cin >> a >> b;
    result = cal_pow(a,b);
    cout << result;
    return 0;
}
