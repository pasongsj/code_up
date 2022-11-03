#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a%b == 0)    return b;
    return gcd(b,a%b);
}
int main(){
    int n;
    cin >> n;
    int ans = 1;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        ans = ans * tmp / gcd(ans,tmp);
    }
    cout << ans;
    return 0;
}
