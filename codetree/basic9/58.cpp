#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,m,sum_val = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        sum_val += m;
    }
    string s = to_string(sum_val);
    cout<<s.substr(1,s.length()-1) + s[0];
    return 0;
}
