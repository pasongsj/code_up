#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout<<a/b<<".";
    a %= b;
    for(int i=0;i<20;i++){
        cout<<a*10/b;
        a = a*10%b;
    }
    return 0;
}
