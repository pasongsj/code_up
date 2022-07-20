#include<iostream>
using namespace std;
int main(){
    int o1,o2;
    char j1,j2;
    cin >> o1 >> j1 >> o2 >> j2;
    if(o1>18 && j1 == 'M' || o2>18 && j2 == 'M')    cout << 1;
    else cout<<0;
    return 0;
}
