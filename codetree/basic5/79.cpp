#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=a;i<=b;i++){
        if(i%c==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
