#include <iostream>
#include <string>
using namespace std;
int main(){
    string str1,str2,str3;
    int a,b,c,tmp1,tmp2;
    cin >> str1 >> str2 >> str3;
    a = str1.length();
    b = str2.length();
    c = str3.length();
    tmp1 = b>c?b:c;
    tmp2 = b<c?b:c;
    cout<<(a>tmp1?a:tmp1)-(a<tmp2?a:tmp2);
    return 0;
}
