#include <iostream>
#include <string>
using namespace std;
int main(){
    string sum_val;
    int s,t,cnt = 0;
    cin >> s >> t;
    sum_val = to_string(s+t);
    for(int i=0;i<sum_val.length();i++){
        if(sum_val[i]=='1') cnt++;
    }
    cout<< cnt;
    return 0;
}
