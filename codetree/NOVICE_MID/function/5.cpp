#include <iostream>
using namespace std;
void PrintRect(int n, int m) {
    int tmp;
    while(m!=0){
        tmp = n%m;
        n = m;
        m = tmp;
    }
    cout<<n;
}
int main(){
    int a,b;
    cin >> a >> b;
    PrintRect(a,b);
    return 0;
}
