#include <iostream>
using namespace std;

int main(){
    int w = 13;
    double p = 0.165;
    cout << fixed;
    cout.precision(6);
    cout << w << " * " << p << " = " << w * p;
    return 0;
}
