#include <iostream>
#include <string>
using namespace std;
int main(){
    string str_a,str_b;
    cin >> str_a >> str_b;
    int cnt = 0;
    for(int i=0;i<str_a.length()-1;i++){
        if(str_a[i]==str_b[0] && str_a[i+1] == str_b[1])    cnt++;
    }
    cout<<cnt;
    return 0;
}


