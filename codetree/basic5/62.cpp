#include <iostream>
using namespace std;
int main(){
    int n,i,tmp;
    cin >> n;
    tmp = n;
    for(i=1;i<=n;i++){
        if((tmp/i)<=1)  break;
        tmp /= i;
    }
    cout << i;
    return 0;
}
