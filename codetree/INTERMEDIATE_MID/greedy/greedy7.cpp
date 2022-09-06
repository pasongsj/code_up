#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    int coin_2, coin_5; 
    if(n%2 == 0){
        coin_5 = n/5/2*2;
        coin_2 = (n - 5*coin_5)/2;
        ans += (coin_2 + coin_5);
    }
    else{
        coin_5 = (n-5)/5/2*2+1;
        coin_2 = (n - 5*coin_5)/2;
        ans += (coin_2 + coin_5);
    }
    if(n == 3 || n < 1)   cout<<-1;
    else    cout<<ans;
    return 0;
}
