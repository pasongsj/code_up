#include <iostream>
using namespace std;
int main(){
    int w,index;
    double l;
    cin >> l >> w;
    l /= 100;
    index = w / (l * l);
    cout << index;
    if(index >= 25) cout << endl << "Obesity";
    return 0;
}
