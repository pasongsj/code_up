#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    for(int i=2;i<10;i+=2){
        for(int j=b;j>=a;j--){
            cout << j << " * "<< i << " = "<< i*j;
            if(j==a)    continue;
            cout << " / ";
        }
        cout << endl;
    }
    return 0;
}
