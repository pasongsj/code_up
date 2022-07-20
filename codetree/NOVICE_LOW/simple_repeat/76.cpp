#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b/c - a/c>0 || a == b && a%c == 0)   cout<<"YES";
    else    cout<<"NO";
    return 0;
}
