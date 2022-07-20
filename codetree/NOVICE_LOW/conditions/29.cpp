#include <iostream>
using namespace std;
int main(){
    double n,m;
    cin >> n >> m;
    if (n >= 1.0 and m >= 1.0)   cout<<"High";
    else if(n >= 0.5 && m >= 0.5) cout<<"Middle";
    else   cout<<"Low";
    return 0;
}
