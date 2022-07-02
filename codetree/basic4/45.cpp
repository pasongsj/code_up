#include<iostream>
using namespace std;
int main(){
    int a, b, c, tmp;
    cin >> a >> b >> c;
    tmp = a > b ? a : b;
    cout << (tmp > c ? tmp : c);
    return 0;
}
