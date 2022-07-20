#include <iostream>
#include <string>
using namespace std;
int main(){
    char a;
    cin >> a;
    if((int)a == 122)   a = 'a';
    else a+=1;
    cout << (char)a;
    return 0;
}
