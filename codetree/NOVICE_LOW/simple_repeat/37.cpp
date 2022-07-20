#include<iostream>
using namespace std;
int main(){
    int n, ans3 = 0, ans5 = 0;
    for(int i=0;i<10;i++){
        cin >> n;
        if(n%3==0)  ans3++;
        if(n%5==0)  ans5++;
    }
    cout << ans3 << ' ' << ans5;
    return 0;
}
