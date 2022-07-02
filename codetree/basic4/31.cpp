#include <iostream>
using namespace std;
int main(){
    int  a, b, c, tmp;
    cin >> a >> b >> c;
    tmp = (a < b)? a : b;
    cout <<  (c < tmp ? c: tmp);
    return 0;
}
