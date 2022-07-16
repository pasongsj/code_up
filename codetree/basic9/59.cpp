#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, cnt = 0;;
    string a,b;
    cin >> n >> a;
    for (int i=0;i<n;i++){
        cin >> b;
        if(a == b)  cnt++;
    }
    cout<<cnt;
    return 0;
}
