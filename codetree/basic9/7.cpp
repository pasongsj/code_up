#include <iostream>
#include <string>
using namespace std;
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    str1 += str2;
    for(int i=0;i<str1.length();i++){
        if(str1[i]==' ')   continue;
        cout<<str1[i];
    }
    return 0;
}
