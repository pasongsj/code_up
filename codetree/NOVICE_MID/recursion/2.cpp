#include <iostream>
using namespace std;
void func1(int a){
    if(a==0)    return;

    func1(a-1);
    cout<<a<<' ';
}

void func2(int a){
    if(a==0)    return;

    cout<<a<<' ';
    func2(a-1);
}

int main(){
    int n;
    cin >> n;
    func1(n);
    cout<<endl;
    func2(n);
    return 0;
}
