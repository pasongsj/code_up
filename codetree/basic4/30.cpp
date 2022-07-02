#include <iostream>
using namespace std;
int main(){
    double a,b, c;
    cin >> a >> b >> c;
    cout << ((a<=b && a<=c) ? "1 ": "0 ");
    cout << ((a == b && b == c) ? 1 : 0);
    return 0;
}
