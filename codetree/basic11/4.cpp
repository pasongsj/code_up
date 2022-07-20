#include <iostream>
using namespace std;
void Print_fun(int n){
    if(n==0)    return;
    cout<<n<<' ';
    Print_fun(n-1);
    cout<<n<<' ';
}

int main(){
    int n;
    cin >> n;
    Print_fun(n);
    return 0;
}
