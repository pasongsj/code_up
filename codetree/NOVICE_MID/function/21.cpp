#include <iostream>
using namespace std;

void cal_f(int &n, int &m){
    int tmp = (m>n?n:m)*2;
    if(n > m){
        n += 25;
        m = tmp;
    }
    else{
        n =tmp;
        m += 25;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    cal_f(a,b);
    cout<<a<<' '<<b;
    return 0;
}
