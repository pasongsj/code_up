#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, sum_val = 0;
    cin >> n;
    string s = to_string(n);
    for(int i=0;i<s.length();i++){
        sum_val += n%10;
        n /= 10;
    }
    cout<<sum_val;
    return 0;
}
    
