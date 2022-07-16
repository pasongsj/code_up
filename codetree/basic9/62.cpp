#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int n = 0;
    while(a != b){
        a = a[a.length()-1] + a.substr(0,a.length()-1);
        n ++;
        if(n>a.length()){
            cout<< -1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
