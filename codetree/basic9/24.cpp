#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string tmp, str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        str += tmp;
    }
    cout<<str;
    return 0;
}
