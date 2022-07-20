#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int n,len;
    cin >> str;
    cin >> n;
    len = str.length();
    for(int i=len-1;i>=((len-n)>0?(len-n):0);i--)   cout<<str[i];
    return 0;
}
