#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    for(int i=1;i<=9;i++){
        for(int j=b;j>=a;j-=2){
            cout << (j/2)*2 << " * " << i << " = "<< (j/2)*2*i;
            if(j == a)  continue;
            cout << " / ";
        }
        cout << endl;
    }
    return 0;
}
